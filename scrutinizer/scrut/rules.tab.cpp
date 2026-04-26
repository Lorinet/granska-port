/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "rules.y"

/* rules.y
 * authors: Viggo Kann and Johan Carlberger
 * last Johan change: 2000-03-24
 * last Viggo change: 1999-11-28
 * comments: Syntaxregler för granskas regelspråk
 */
  
// #define LEXTEST    /* testutskrifter vid användning av lex-attributet */
// #define TESTGLOBAL /* skriv ut alla globala symboler */
// #define TESTEVAL   /* test av uttrycksevaluering */

extern "C" {
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stavaapi.h"
}
#include "scrutinizer.h"
#include "rules.h"
#include "ruleset.h"
#include "rulesettings.h"
//#include "matching.h"
#include "letter.h"

#define MAXNOOFARGUMENTS 10 /* max number of arguments to any method or function in the rule language */
#define MAXLINELENGTH 1000  /* max length of line in rules */


Scrutinizer *scrutinizer;       // slightly faster if not pointer

static int yylex(void);                /* lexical analyzer */
static int yyerror(char *s);           /* automatically called error reporting function */

/* Definierade i regexps.cc: */
/* CompileRegexpHelp compiles valregexp */
char *CompileRegexpHelp(const char *valregexp);

/* RegexpCheckHelp checks if regular expression in valcompiled matches s */
int RegexpCheckHelp(const char *s, const char *valcompiled);

/* exprUse tells in which context expr is used */
static enum exprusetype {InConst, InLHS, InMark, InCorr, InJump, InInfo, 
			 InAction } exprUse;

			 /*
static bool IsNumber(enum semantictype semtype)
{ return semtype == Integer || semtype == Real; }

static bool IsFeature(enum semantictype semtype)
{ return semtype == SemFeatureClass || semtype == Feature; }

static enum semantictype HighestType(enum semantictype t1, enum semantictype t2)
{
 if (t1 == Real && t2 == Integer) return Real;
 if (t2 == Real && t1 == Integer) return Real;
 return t1;
}
*/

static bool Compatible(const Expr *a, const Expr *b);

int hashcode = 0L;
static int line = 0; /* radnummer */
static char linebuf[MAXLINELENGTH]; /* senaste raden */
static int errorLine = 0; /* radnummer vid senaste anrop av yyerror */
static char errorLineBuf[MAXLINELENGTH]; /* raden vid senaste anrop av yyerror */
RuleSet ruleSet;
/* Variabler som används för uppbyggnad av listor: */
static RuleTerm *firstAltRule = NULL;
static RuleTerm *firstlhs = NULL;
static Element tempElements[MAXNOOFELEMENTS];

static char *currentElementName = NULL;
int currentNoOfElement = 0; /* nr på aktuellt element inom regeln under parsning */
int endLeftContext = -1, beginRightContext = -1; /* kontextgränser inom regeln under parsning */
int noCodeGeneration = 0; /* 1 om kodgenerering inte ska ske */

static Expr *constantAlmostOne, *constantAlmostZero;
Expr *constantTrue, *constantFalse;
static IdEntry *endlabel; /* the label end: */
IdEntry *constantRealText;
IdEntry *constantText;
IdEntry *constantVerbtype;
IdEntry *constantReplace;
IdEntry *constantLemma;

static IdEntry *constantNoOfTokens, *constantToken;
static IdEntry *constantSpellOK, *constantBeginOK, *constantEndOK, *constantIsRepeated;
static IdEntry *constantLength, *constantGetReplacement, *constantGetValues;
static IdEntry *constantLex, *constantCap, *constantAllCap, *constantIsForeign;

static Expr *DotExpr(Expr *left, Expr *right);
static Expr *AssignExpr(Expr *lhs, Expr *rhs);
static Expr *IfExpr(Expr *cond, Expr *trueExpr, Expr *elseExpr);

StringBuf infoStringBuf;
StringBuf evalStringBuf;

/* CompileRegexp compiles the regexp in val.string */


static int CompileRegexp(union value&) { return 0; }
static bool RegexpCheck(const char*, union value, enum semantictype) {
  return false; }



#line 180 "rules.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "rules.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INTEGERSYM = 3,                 /* INTEGERSYM  */
  YYSYMBOL_REALSYM = 4,                    /* REALSYM  */
  YYSYMBOL_STRINGSYM = 5,                  /* STRINGSYM  */
  YYSYMBOL_UNDEFIDENTSYM = 6,              /* UNDEFIDENTSYM  */
  YYSYMBOL_VARIDENTSYM = 7,                /* VARIDENTSYM  */
  YYSYMBOL_ATTRIDENTSYM = 8,               /* ATTRIDENTSYM  */
  YYSYMBOL_CONSTIDENTSYM = 9,              /* CONSTIDENTSYM  */
  YYSYMBOL_TAGIDENTSYM = 10,               /* TAGIDENTSYM  */
  YYSYMBOL_CHECKIDENTSYM = 11,             /* CHECKIDENTSYM  */
  YYSYMBOL_LOOKUPIDENTSYM = 12,            /* LOOKUPIDENTSYM  */
  YYSYMBOL_LABELIDENTSYM = 13,             /* LABELIDENTSYM  */
  YYSYMBOL_EDITIDENTSYM = 14,              /* EDITIDENTSYM  */
  YYSYMBOL_HELPIDENTSYM = 15,              /* HELPIDENTSYM  */
  YYSYMBOL_ACCEPTIDENTSYM = 16,            /* ACCEPTIDENTSYM  */
  YYSYMBOL_RULEIDENTSYM = 17,              /* RULEIDENTSYM  */
  YYSYMBOL_RULEELEMENTIDENTSYM = 18,       /* RULEELEMENTIDENTSYM  */
  YYSYMBOL_UNDEFIDENTSYMAT = 19,           /* UNDEFIDENTSYMAT  */
  YYSYMBOL_RULEIDENTSYMAT = 20,            /* RULEIDENTSYMAT  */
  YYSYMBOL_FUNCIDENTSYM = 21,              /* FUNCIDENTSYM  */
  YYSYMBOL_METHIDENTSYM = 22,              /* METHIDENTSYM  */
  YYSYMBOL_ARROWSYM = 23,                  /* ARROWSYM  */
  YYSYMBOL_PROBSYM = 24,                   /* PROBSYM  */
  YYSYMBOL_FORALLSYM = 25,                 /* FORALLSYM  */
  YYSYMBOL_EXISTSYM = 26,                  /* EXISTSYM  */
  YYSYMBOL_IFSYM = 27,                     /* IFSYM  */
  YYSYMBOL_THENSYM = 28,                   /* THENSYM  */
  YYSYMBOL_ELSESYM = 29,                   /* ELSESYM  */
  YYSYMBOL_ENDSYM = 30,                    /* ENDSYM  */
  YYSYMBOL_CONSTSYM = 31,                  /* CONSTSYM  */
  YYSYMBOL_GOTOSYM = 32,                   /* GOTOSYM  */
  YYSYMBOL_MARKSYM = 33,                   /* MARKSYM  */
  YYSYMBOL_CORRSYM = 34,                   /* CORRSYM  */
  YYSYMBOL_JUMPSYM = 35,                   /* JUMPSYM  */
  YYSYMBOL_INFOSYM = 36,                   /* INFOSYM  */
  YYSYMBOL_CATEGORYSYM = 37,               /* CATEGORYSYM  */
  YYSYMBOL_ACTIONSYM = 38,                 /* ACTIONSYM  */
  YYSYMBOL_DETECTSYM = 39,                 /* DETECTSYM  */
  YYSYMBOL_ACCEPTSYM = 40,                 /* ACCEPTSYM  */
  YYSYMBOL_LINKSYM = 41,                   /* LINKSYM  */
  YYSYMBOL_ENDLEFTCONTEXTSYM = 42,         /* ENDLEFTCONTEXTSYM  */
  YYSYMBOL_BEGINRIGHTCONTEXTSYM = 43,      /* BEGINRIGHTCONTEXTSYM  */
  YYSYMBOL_ASSIGNSYM = 44,                 /* ASSIGNSYM  */
  YYSYMBOL_45_ = 45,                       /* '|'  */
  YYSYMBOL_46_ = 46,                       /* '&'  */
  YYSYMBOL_47_ = 47,                       /* '!'  */
  YYSYMBOL_48_ = 48,                       /* '='  */
  YYSYMBOL_49_ = 49,                       /* '<'  */
  YYSYMBOL_50_ = 50,                       /* '>'  */
  YYSYMBOL_NESYM = 51,                     /* NESYM  */
  YYSYMBOL_LESYM = 52,                     /* LESYM  */
  YYSYMBOL_GESYM = 53,                     /* GESYM  */
  YYSYMBOL_54_ = 54,                       /* '~'  */
  YYSYMBOL_55_ = 55,                       /* '+'  */
  YYSYMBOL_56_ = 56,                       /* '-'  */
  YYSYMBOL_NEG = 57,                       /* NEG  */
  YYSYMBOL_58_ = 58,                       /* '['  */
  YYSYMBOL_59_ = 59,                       /* '.'  */
  YYSYMBOL_60_ = 60,                       /* ';'  */
  YYSYMBOL_61_ = 61,                       /* '{'  */
  YYSYMBOL_62_ = 62,                       /* '('  */
  YYSYMBOL_63_ = 63,                       /* ')'  */
  YYSYMBOL_64_ = 64,                       /* '}'  */
  YYSYMBOL_65_ = 65,                       /* '/'  */
  YYSYMBOL_66_ = 66,                       /* ':'  */
  YYSYMBOL_67_ = 67,                       /* '@'  */
  YYSYMBOL_68_ = 68,                       /* ','  */
  YYSYMBOL_69_ = 69,                       /* '*'  */
  YYSYMBOL_70_ = 70,                       /* '?'  */
  YYSYMBOL_71_ = 71,                       /* ']'  */
  YYSYMBOL_YYACCEPT = 72,                  /* $accept  */
  YYSYMBOL_program = 73,                   /* program  */
  YYSYMBOL_constdeclarations = 74,         /* constdeclarations  */
  YYSYMBOL_75_1 = 75,                      /* $@1  */
  YYSYMBOL_rules = 76,                     /* rules  */
  YYSYMBOL_category = 77,                  /* category  */
  YYSYMBOL_rule = 78,                      /* rule  */
  YYSYMBOL_79_2 = 79,                      /* @2  */
  YYSYMBOL_80_3 = 80,                      /* $@3  */
  YYSYMBOL_81_4 = 81,                      /* @4  */
  YYSYMBOL_newscope = 82,                  /* newscope  */
  YYSYMBOL_maybename = 83,                 /* maybename  */
  YYSYMBOL_altrules = 84,                  /* altrules  */
  YYSYMBOL_85_5 = 85,                      /* $@5  */
  YYSYMBOL_altrule = 86,                   /* altrule  */
  YYSYMBOL_87_6 = 87,                      /* @6  */
  YYSYMBOL_88_7 = 88,                      /* @7  */
  YYSYMBOL_rhslist = 89,                   /* rhslist  */
  YYSYMBOL_rhs = 90,                       /* rhs  */
  YYSYMBOL_setmark = 91,                   /* setmark  */
  YYSYMBOL_setcorr = 92,                   /* setcorr  */
  YYSYMBOL_setjump = 93,                   /* setjump  */
  YYSYMBOL_setinfo = 94,                   /* setinfo  */
  YYSYMBOL_setaction = 95,                 /* setaction  */
  YYSYMBOL_gbglhslist = 96,                /* gbglhslist  */
  YYSYMBOL_lhs = 97,                       /* lhs  */
  YYSYMBOL_elements = 98,                  /* elements  */
  YYSYMBOL_99_8 = 99,                      /* $@8  */
  YYSYMBOL_element = 100,                  /* element  */
  YYSYMBOL_101_9 = 101,                    /* $@9  */
  YYSYMBOL_102_10 = 102,                   /* $@10  */
  YYSYMBOL_103_11 = 103,                   /* $@11  */
  YYSYMBOL_elementname = 104,              /* elementname  */
  YYSYMBOL_helprule = 105,                 /* helprule  */
  YYSYMBOL_maybeocc = 106,                 /* maybeocc  */
  YYSYMBOL_mark = 107,                     /* mark  */
  YYSYMBOL_corr = 108,                     /* corr  */
  YYSYMBOL_jump = 109,                     /* jump  */
  YYSYMBOL_info = 110,                     /* info  */
  YYSYMBOL_action = 111,                   /* action  */
  YYSYMBOL_actionident = 112,              /* actionident  */
  YYSYMBOL_maybeexpr = 113,                /* maybeexpr  */
  YYSYMBOL_expr = 114,                     /* expr  */
  YYSYMBOL_115_12 = 115,                   /* $@12  */
  YYSYMBOL_methodorattribute = 116,        /* methodorattribute  */
  YYSYMBOL_arglist = 117,                  /* arglist  */
  YYSYMBOL_args = 118,                     /* args  */
  YYSYMBOL_exprseq = 119                   /* exprseq  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   784

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  72
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  48
/* YYNRULES -- Number of rules.  */
#define YYNRULES  149
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  295

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   303


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    47,     2,     2,     2,     2,    46,     2,
      62,    63,    69,    55,    68,    56,    59,    65,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    66,    60,
      49,    48,    50,    70,    67,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    58,     2,    71,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    61,    45,    64,    54,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      51,    52,    53,    57
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   158,   158,   161,   162,   162,   168,   169,   173,   174,
     175,   176,   179,   182,   189,   190,   189,   196,   195,   216,
     217,   220,   223,   224,   227,   231,   234,   237,   241,   242,
     243,   243,   247,   247,   254,   254,   261,   262,   265,   267,
     268,   269,   270,   271,   272,   273,   274,   277,   280,   283,
     286,   289,   292,   296,   303,   306,   307,   308,   308,   310,
     314,   317,   313,   332,   331,   334,   339,   345,   349,   354,
     355,   358,   363,   367,   371,   377,   381,   387,   388,   391,
     392,   393,   396,   397,   400,   401,   402,   405,   406,   409,
     413,   419,   423,   426,   427,   428,   431,   432,   433,   436,
     439,   440,   441,   442,   443,   444,   447,   448,   451,   453,
     455,   457,   459,   461,   462,   467,   468,   469,   470,   471,
     472,   484,   487,   497,   500,   502,   504,   506,   508,   512,
     516,   517,   520,   523,   524,   532,   536,   539,   542,   542,
     545,   549,   554,   563,   564,   565,   568,   569,   572,   573
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "INTEGERSYM",
  "REALSYM", "STRINGSYM", "UNDEFIDENTSYM", "VARIDENTSYM", "ATTRIDENTSYM",
  "CONSTIDENTSYM", "TAGIDENTSYM", "CHECKIDENTSYM", "LOOKUPIDENTSYM",
  "LABELIDENTSYM", "EDITIDENTSYM", "HELPIDENTSYM", "ACCEPTIDENTSYM",
  "RULEIDENTSYM", "RULEELEMENTIDENTSYM", "UNDEFIDENTSYMAT",
  "RULEIDENTSYMAT", "FUNCIDENTSYM", "METHIDENTSYM", "ARROWSYM", "PROBSYM",
  "FORALLSYM", "EXISTSYM", "IFSYM", "THENSYM", "ELSESYM", "ENDSYM",
  "CONSTSYM", "GOTOSYM", "MARKSYM", "CORRSYM", "JUMPSYM", "INFOSYM",
  "CATEGORYSYM", "ACTIONSYM", "DETECTSYM", "ACCEPTSYM", "LINKSYM",
  "ENDLEFTCONTEXTSYM", "BEGINRIGHTCONTEXTSYM", "ASSIGNSYM", "'|'", "'&'",
  "'!'", "'='", "'<'", "'>'", "NESYM", "LESYM", "GESYM", "'~'", "'+'",
  "'-'", "NEG", "'['", "'.'", "';'", "'{'", "'('", "')'", "'}'", "'/'",
  "':'", "'@'", "','", "'*'", "'?'", "']'", "$accept", "program",
  "constdeclarations", "$@1", "rules", "category", "rule", "@2", "$@3",
  "@4", "newscope", "maybename", "altrules", "$@5", "altrule", "@6", "@7",
  "rhslist", "rhs", "setmark", "setcorr", "setjump", "setinfo",
  "setaction", "gbglhslist", "lhs", "elements", "$@8", "element", "$@9",
  "$@10", "$@11", "elementname", "helprule", "maybeocc", "mark", "corr",
  "jump", "info", "action", "actionident", "maybeexpr", "expr", "$@12",
  "methodorattribute", "arglist", "args", "exprseq", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-193)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-61)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -193,    11,    -1,  -193,   -38,   -35,  -193,  -193,    23,    57,
    -193,   287,  -193,  -193,    -9,     7,     7,   -14,    53,    39,
    -193,  -193,    52,  -193,  -193,  -193,  -193,  -193,    63,   164,
      47,  -193,  -193,    49,   274,   111,    55,  -193,    95,    42,
    -193,   159,   455,    58,  -193,  -193,  -193,  -193,  -193,  -193,
      -8,    65,  -193,    71,    78,    84,    85,    91,    87,    93,
    -193,  -193,  -193,    94,   173,  -193,    96,   455,  -193,  -193,
    -193,  -193,  -193,  -193,  -193,  -193,    31,    31,   107,   116,
     120,   263,   455,   428,   654,  -193,   192,  -193,   276,    49,
     147,   145,   204,   211,   212,   157,  -193,   197,   276,  -193,
    -193,   455,  -193,   160,   671,   162,   338,  -193,  -193,   455,
     455,   455,   199,   460,   713,   455,   542,   455,   455,   455,
     455,   455,   455,   455,   455,   455,   455,   455,   455,   455,
      13,  -193,   167,    88,   -17,  -193,  -193,    49,  -193,  -193,
    -193,  -193,  -193,  -193,  -193,    97,   183,     1,  -193,  -193,
    -193,   500,   184,   521,   558,   574,  -193,  -193,   590,  -193,
     687,   701,   713,   725,   725,   725,   725,   725,   725,   117,
     -50,   -50,   476,  -193,  -193,   186,   185,   174,   190,   191,
     193,   194,   203,   214,   216,  -193,   -16,  -193,  -193,  -193,
    -193,  -193,  -193,  -193,     1,   455,  -193,   455,  -193,  -193,
     455,  -193,  -193,   217,  -193,  -193,  -193,  -193,  -193,  -193,
     254,   268,   269,   250,   106,  -193,  -193,   606,   368,   266,
     291,   308,   187,     9,   236,   188,   229,   234,   296,   240,
    -193,  -193,  -193,   455,   298,   241,  -193,   242,   245,  -193,
    -193,   257,   258,   -21,    38,  -193,  -193,   259,  -193,  -193,
     260,   264,  -193,  -193,  -193,  -193,  -193,  -193,  -193,  -193,
      40,  -193,  -193,   265,  -193,   301,   273,  -193,  -193,  -193,
    -193,  -193,  -193,   455,  -193,   455,  -193,  -193,  -193,  -193,
     455,  -193,   236,  -193,   275,   622,   638,   277,   285,  -193,
    -193,  -193,  -193,   286,  -193
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,    22,     1,     0,     0,    25,    26,     0,     0,
      27,     2,     8,     9,     0,    22,    22,     0,     0,     0,
      10,    11,     0,    23,    24,     7,     6,     4,     0,     0,
       0,    65,    66,     0,     0,     0,     0,    28,     0,     0,
      55,     0,     0,     0,    34,    30,    70,    20,    59,    67,
       0,    14,    52,     0,    71,    72,    73,     0,     0,     0,
      21,    13,    32,     0,     0,    57,     0,   106,   109,   108,
     110,   116,   111,   141,   115,   112,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   113,     0,    36,     0,     0,
       0,     0,     0,     0,     0,     0,    19,     0,     0,    36,
      56,   106,    63,     0,   107,     0,     0,   114,   142,     0,
       0,     0,     0,     0,   131,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     5,     0,     0,     0,    31,    53,     0,    69,    74,
      75,    76,    68,    17,    29,     0,     0,    77,    61,   145,
     144,   146,     0,     0,     0,     0,   140,   138,     0,   133,
     130,   129,   128,   121,   126,   127,   123,   124,   125,   122,
     119,   120,     0,   118,   117,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    37,     0,    36,    58,    78,
      80,    79,    81,    64,    77,     0,   143,     0,   136,   137,
       0,   132,   134,     0,    46,    47,    48,    49,    50,    51,
       0,     0,     0,     0,     0,    62,   147,     0,   148,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      18,   135,   149,     0,     0,     0,    38,     0,     0,    84,
      39,     0,     0,     0,     0,    87,    40,     0,    93,    41,
       0,     0,   100,   101,   102,   103,   104,   105,    96,    42,
       0,    43,    44,     0,    15,     0,     0,    83,    82,    86,
      85,    92,    88,     0,    89,     0,    95,    94,    99,    97,
       0,    45,     0,   139,     0,     0,     0,     0,     0,    12,
      90,    91,    98,     0,    16
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -193,  -193,  -193,  -193,  -193,   326,   340,  -193,  -193,  -193,
    -193,    46,  -193,  -193,   -65,  -193,  -193,   -97,  -193,  -193,
    -193,  -193,  -193,  -193,   215,   -32,  -193,  -193,   289,  -193,
    -193,  -193,   318,  -193,   172,  -193,  -193,  -193,    76,  -193,
    -193,   267,   -42,  -193,   231,   290,  -192,  -184
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,     2,    42,    11,    12,    13,    90,   282,   187,
      98,    14,    36,    88,    37,    99,    87,   133,   185,   221,
     222,   223,   224,   225,    51,    38,    39,   101,    40,    67,
     194,   147,    41,    57,   193,   236,   240,   246,   249,   259,
     260,   103,   218,   200,    85,   107,   152,   250
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      84,    52,   145,   216,   189,     4,    44,   213,   129,   130,
     242,     3,     5,     4,   173,   243,   219,    25,     6,     7,
       5,    73,   244,   135,    17,   104,     6,     7,    15,    18,
       8,    16,   105,   144,   232,    77,     9,   237,   241,   113,
     114,   116,   272,    63,    89,    46,    26,   273,    30,   265,
      50,    48,    22,    29,    46,    30,   190,   136,    30,   104,
      48,    23,    24,    19,   151,   -54,    10,   153,   154,   155,
     191,   192,   245,   158,    10,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   287,   176,
     214,    31,    32,   106,    31,    32,   -54,    27,   176,    43,
      28,   274,   -54,   279,    34,    52,   275,   176,   280,    49,
      64,    34,    58,    33,    34,    60,    59,    35,    62,    61,
      86,   177,   178,   179,   180,    89,   181,   182,   183,   184,
     177,   178,   179,   180,    91,   181,   182,   183,   184,   177,
     178,   179,   180,    92,   181,   182,   183,   184,   -35,    93,
      94,    96,   -35,   151,    95,   217,    46,   -33,    97,   102,
      66,   -33,   -60,   -60,   -60,   -60,   -60,   -60,   -60,   109,
     230,   -61,   127,   128,    63,   129,   130,   -60,   110,    30,
     -60,   -60,   111,   -60,   -60,   -60,   -60,    44,   238,   251,
      68,    69,    70,    71,    72,    73,    74,   132,   252,   253,
     254,   137,   255,   256,   257,    75,   -60,   138,    76,    77,
     139,    78,    79,    80,    81,    31,    32,   140,   141,   142,
     143,   -60,   -60,   148,    45,   149,    46,   203,    47,   156,
     175,   285,    48,   286,    82,    34,   205,   247,   151,    68,
      69,    70,    71,    72,    73,    74,   188,   196,   204,    83,
     239,   258,   206,   207,    75,   208,   209,    76,    77,   226,
      78,    79,    80,    81,   112,   210,    68,    69,    70,    71,
      72,    73,    74,   227,   228,    53,   211,   134,   212,   220,
      54,    75,    30,    82,    76,    77,   229,    78,    79,    80,
      81,    55,   261,     4,    56,   233,   234,   262,    83,   248,
       5,   263,   264,   266,   267,   268,     6,     7,   269,   235,
      82,    68,    69,    70,    71,    72,    73,    74,    31,    32,
     270,   271,   276,   277,     9,    83,    75,   278,   281,    76,
      77,   283,    78,    79,    80,    81,   284,    20,    34,   289,
     292,    68,    69,    70,    71,    72,    73,    74,   -22,   293,
     294,    21,   186,   100,    10,    82,    75,    65,   288,    76,
      77,   174,    78,    79,    80,    81,   215,   108,   146,     0,
      83,    68,    69,    70,    71,    72,    73,    74,     0,     0,
       0,     0,     0,     0,     0,    82,    75,     0,     0,    76,
      77,     0,    78,    79,    80,    81,     0,     0,     0,     0,
      83,   150,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   117,   118,   119,    82,   120,   121,   122,   123,
     124,   125,   126,   127,   128,     0,   129,   130,     0,     0,
      83,    68,    69,    70,    71,    72,    73,    74,     0,     0,
       0,     0,     0,     0,     0,     0,    75,     0,     0,    76,
      77,     0,    78,    79,    80,    81,     0,     0,    68,    69,
      70,    71,    72,    73,    74,     0,     0,     0,     0,     0,
       0,     0,     0,    75,     0,    82,    76,    77,     0,    78,
      79,    80,    81,     0,   115,     0,     0,     0,   157,     0,
      83,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    82,     0,   117,   118,   119,     0,   120,   121,
     122,   123,   124,   125,   126,   127,   128,    83,   129,   130,
     117,   118,   119,     0,   120,   121,   122,   123,   124,   125,
     126,   127,   128,     0,   129,   130,     0,     0,     0,     0,
       0,     0,     0,     0,   117,   118,   119,   202,   120,   121,
     122,   123,   124,   125,   126,   127,   128,     0,   129,   130,
       0,     0,     0,     0,     0,   117,   118,   119,   195,   120,
     121,   122,   123,   124,   125,   126,   127,   128,     0,   129,
     130,     0,     0,     0,     0,     0,   117,   118,   119,   197,
     120,   121,   122,   123,   124,   125,   126,   127,   128,     0,
     129,   130,   117,   118,   119,   159,   120,   121,   122,   123,
     124,   125,   126,   127,   128,     0,   129,   130,   117,   118,
     119,   198,   120,   121,   122,   123,   124,   125,   126,   127,
     128,     0,   129,   130,   117,   118,   119,   199,   120,   121,
     122,   123,   124,   125,   126,   127,   128,     0,   129,   130,
     117,   118,   119,   201,   120,   121,   122,   123,   124,   125,
     126,   127,   128,     0,   129,   130,   117,   118,   119,   231,
     120,   121,   122,   123,   124,   125,   126,   127,   128,     0,
     129,   130,   117,   118,   119,   290,   120,   121,   122,   123,
     124,   125,   126,   127,   128,     0,   129,   130,   117,   118,
     119,   291,   120,   121,   122,   123,   124,   125,   126,   127,
     128,     0,   129,   130,   131,   117,   118,   119,     0,   120,
     121,   122,   123,   124,   125,   126,   127,   128,     0,   129,
     130,   -61,   118,   119,     0,   120,   121,   122,   123,   124,
     125,   126,   127,   128,     0,   129,   130,   119,     0,   120,
     121,   122,   123,   124,   125,   126,   127,   128,     0,   129,
     130,   120,   121,   122,   123,   124,   125,   126,   127,   128,
       0,   129,   130,   -61,   -61,   -61,   -61,   -61,   -61,   126,
     127,   128,     0,   129,   130
};

static const yytype_int16 yycheck[] =
{
      42,    33,    99,   195,     3,     6,    23,    23,    58,    59,
       1,     0,    13,     6,     1,     6,   200,    31,    19,    20,
      13,     8,    13,    88,     1,    67,    19,    20,    66,     6,
      31,    66,     1,    98,   218,    22,    37,   221,   222,    81,
      82,    83,    63,     1,    60,    62,    60,    68,     6,   233,
       1,    68,    61,     1,    62,     6,    55,    89,     6,   101,
      68,    15,    16,     6,   106,    23,    67,   109,   110,   111,
      69,    70,    63,   115,    67,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   280,     1,
     187,    42,    43,    62,    42,    43,    54,    44,     1,    36,
      61,    63,    60,    63,    62,   137,    68,     1,    68,    62,
      68,    62,     1,    61,    62,    60,     5,    65,    23,    64,
      62,    33,    34,    35,    36,    60,    38,    39,    40,    41,
      33,    34,    35,    36,    63,    38,    39,    40,    41,    33,
      34,    35,    36,    65,    38,    39,    40,    41,    60,    65,
      65,    64,    64,   195,    63,   197,    62,    60,    65,    63,
       1,    64,     3,     4,     5,     6,     7,     8,     9,    62,
      64,    54,    55,    56,     1,    58,    59,    18,    62,     6,
      21,    22,    62,    24,    25,    26,    27,    23,     1,     1,
       3,     4,     5,     6,     7,     8,     9,     5,    10,    11,
      12,    54,    14,    15,    16,    18,    47,    62,    21,    22,
       6,    24,    25,    26,    27,    42,    43,     6,     6,    62,
      23,    62,    63,    63,    60,    63,    62,    41,    64,    30,
      63,   273,    68,   275,    47,    62,    62,     1,   280,     3,
       4,     5,     6,     7,     8,     9,    63,    63,    63,    62,
      63,    63,    62,    62,    18,    62,    62,    21,    22,     5,
      24,    25,    26,    27,     1,    62,     3,     4,     5,     6,
       7,     8,     9,     5,     5,     1,    62,     1,    62,    62,
       6,    18,     6,    47,    21,    22,    36,    24,    25,    26,
      27,    17,    63,     6,    20,    29,     5,    63,    62,    63,
      13,     5,    62,     5,    63,    63,    19,    20,    63,     1,
      47,     3,     4,     5,     6,     7,     8,     9,    42,    43,
      63,    63,    63,    63,    37,    62,    18,    63,    63,    21,
      22,    30,    24,    25,    26,    27,    63,    11,    62,    64,
      63,     3,     4,     5,     6,     7,     8,     9,    61,    64,
      64,    11,   137,    64,    67,    47,    18,    39,   282,    21,
      22,   130,    24,    25,    26,    27,   194,    77,   101,    -1,
      62,     3,     4,     5,     6,     7,     8,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    47,    18,    -1,    -1,    21,
      22,    -1,    24,    25,    26,    27,    -1,    -1,    -1,    -1,
      62,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    -1,    58,    59,    -1,    -1,
      62,     3,     4,     5,     6,     7,     8,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,    -1,    21,
      22,    -1,    24,    25,    26,    27,    -1,    -1,     3,     4,
       5,     6,     7,     8,     9,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    18,    -1,    47,    21,    22,    -1,    24,
      25,    26,    27,    -1,    56,    -1,    -1,    -1,    28,    -1,
      62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    47,    -1,    44,    45,    46,    -1,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    62,    58,    59,
      44,    45,    46,    -1,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    -1,    58,    59,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    44,    45,    46,    71,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    -1,    58,    59,
      -1,    -1,    -1,    -1,    -1,    44,    45,    46,    68,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    -1,    58,
      59,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,    68,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    -1,
      58,    59,    44,    45,    46,    63,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    -1,    58,    59,    44,    45,
      46,    63,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    -1,    58,    59,    44,    45,    46,    63,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    -1,    58,    59,
      44,    45,    46,    63,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    -1,    58,    59,    44,    45,    46,    63,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    -1,
      58,    59,    44,    45,    46,    63,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    -1,    58,    59,    44,    45,
      46,    63,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    -1,    58,    59,    60,    44,    45,    46,    -1,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    -1,    58,
      59,    44,    45,    46,    -1,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    -1,    58,    59,    46,    -1,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    -1,    58,
      59,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      -1,    58,    59,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    -1,    58,    59
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    73,    74,     0,     6,    13,    19,    20,    31,    37,
      67,    76,    77,    78,    83,    66,    66,     1,     6,     6,
      77,    78,    61,    83,    83,    31,    60,    44,    61,     1,
       6,    42,    43,    61,    62,    65,    84,    86,    97,    98,
     100,   104,    75,    36,    23,    60,    62,    64,    68,    62,
       1,    96,    97,     1,     6,    17,    20,   105,     1,     5,
      60,    64,    23,     1,    68,   104,     1,   101,     3,     4,
       5,     6,     7,     8,     9,    18,    21,    22,    24,    25,
      26,    27,    47,    62,   114,   116,    62,    88,    85,    60,
      79,    63,    65,    65,    65,    63,    64,    65,    82,    87,
     100,    99,    63,   113,   114,     1,    62,   117,   117,    62,
      62,    62,     1,   114,   114,    56,   114,    44,    45,    46,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    58,
      59,    60,     5,    89,     1,    86,    97,    54,    62,     6,
       6,     6,    62,    23,    86,    89,   113,   103,    63,    63,
      63,   114,   118,   114,   114,   114,    30,    28,   114,    63,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,     1,   116,    63,     1,    33,    34,    35,
      36,    38,    39,    40,    41,    90,    96,    81,    63,     3,
      55,    69,    70,   106,   102,    68,    63,    68,    63,    63,
     115,    63,    71,    41,    63,    62,    62,    62,    62,    62,
      62,    62,    62,    23,    89,   106,   118,   114,   114,   119,
      62,    91,    92,    93,    94,    95,     5,     5,     5,    36,
      64,    63,   119,    29,     5,     1,   107,   119,     1,    63,
     108,   119,     1,     6,    13,    63,   109,     1,    63,   110,
     119,     1,    10,    11,    12,    14,    15,    16,    63,   111,
     112,    63,    63,     5,    62,   119,     5,    63,    63,    63,
      63,    63,    63,    68,    63,    68,    63,    63,    63,    63,
      68,    63,    80,    30,    63,   114,   114,   118,   110,    64,
      63,    63,    63,    64,    64
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    72,    73,    74,    75,    74,    74,    74,    76,    76,
      76,    76,    77,    78,    79,    80,    78,    81,    78,    78,
      78,    82,    83,    83,    83,    83,    83,    83,    84,    84,
      85,    84,    87,    86,    88,    86,    89,    89,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    91,    92,    93,
      94,    95,    96,    96,    97,    98,    98,    99,    98,    98,
     101,   102,   100,   103,   100,   100,   100,   104,   104,   104,
     104,   105,   105,   105,   105,   105,   105,   106,   106,   106,
     106,   106,   107,   107,   108,   108,   108,   109,   109,   109,
     109,   109,   109,   110,   110,   110,   111,   111,   111,   111,
     112,   112,   112,   112,   112,   112,   113,   113,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   115,   114,
     114,   116,   116,   117,   117,   117,   118,   118,   119,   119
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     0,     7,     4,     4,     1,     1,
       2,     2,    13,     4,     0,     0,    14,     0,     9,     5,
       4,     0,     0,     3,     3,     1,     1,     1,     1,     4,
       0,     4,     0,     4,     0,     4,     0,     2,     4,     4,
       4,     4,     4,     4,     4,     5,     2,     0,     0,     0,
       0,     0,     1,     3,     1,     1,     3,     0,     5,     2,
       0,     0,     6,     0,     5,     1,     1,     2,     4,     4,
       2,     1,     1,     1,     3,     3,     3,     0,     1,     1,
       1,     1,     2,     2,     1,     2,     2,     1,     2,     2,
       4,     4,     2,     1,     2,     2,     1,     2,     4,     2,
       1,     1,     1,     1,     1,     1,     0,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     4,     3,     4,     6,     4,     4,     0,     8,
       3,     1,     2,     3,     2,     2,     1,     3,     1,     2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 4: /* $@1: %empty  */
#line 162 "rules.y"
                                                             { exprUse = InConst; }
#line 1588 "rules.tab.c"
    break;

  case 5: /* constdeclarations: constdeclarations CONSTSYM UNDEFIDENTSYM ASSIGNSYM $@1 expr ';'  */
#line 164 "rules.y"
            { (yyvsp[-4].identifier)->IntoGlobalTable(IdEntry::ConstantId);
	      (yyvsp[-4].identifier)->semtype = (yyvsp[-1].node)->semtype;
	      (yyvsp[-4].identifier)->u.expr = (yyvsp[-1].node);
	    }
#line 1597 "rules.tab.c"
    break;

  case 6: /* constdeclarations: constdeclarations CONSTSYM error ';'  */
#line 168 "rules.y"
                                               { ParseError("Fel i konstantdeklaration"); }
#line 1603 "rules.tab.c"
    break;

  case 7: /* constdeclarations: constdeclarations CONSTSYM error CONSTSYM  */
#line 169 "rules.y"
                                                    { ParseError("Konstantdeklarationen måste avslutas med ';'"); YYABORT; }
#line 1609 "rules.tab.c"
    break;

  case 12: /* category: CATEGORYSYM UNDEFIDENTSYM '{' INFOSYM '(' STRINGSYM ')' LINKSYM '(' STRINGSYM STRINGSYM ')' '}'  */
#line 179 "rules.y"
                                                                                                           { ruleSet.AddCategory((yyvsp[-11].identifier)->Name(), (yyvsp[-7].string), (yyvsp[-3].string), (yyvsp[-2].string)); }
#line 1615 "rules.tab.c"
    break;

  case 13: /* rule: maybename '{' altrules '}'  */
#line 182 "rules.y"
                                     {
           if (firstAltRule->IsHelp())
	     ruleSet.Add(new HelpRule((yyvsp[-3].identifier), firstAltRule));
	   else
	     ruleSet.Add(new Rule((yyvsp[-3].identifier), firstAltRule));
	   IdEntry::NewScope();
           }
#line 1627 "rules.tab.c"
    break;

  case 14: /* @2: %empty  */
#line 189 "rules.y"
                                       { (yyval.ruleTerm) = firstlhs; }
#line 1633 "rules.tab.c"
    break;

  case 15: /* $@3: %empty  */
#line 190 "rules.y"
                                                { exprUse = InInfo; }
#line 1639 "rules.tab.c"
    break;

  case 16: /* rule: maybename '{' '{' gbglhslist @2 '~' gbglhslist ARROWSYM INFOSYM '(' $@3 info '}' '}'  */
#line 191 "rules.y"
          {
	    ruleSet.Add(new GbgRule((yyvsp[-13].identifier), (yyvsp[-9].ruleTerm), firstlhs, (yyvsp[-2].node)));
	    IdEntry::NewScope();
	  }
#line 1648 "rules.tab.c"
    break;

  case 17: /* @4: %empty  */
#line 196 "rules.y"
                   { (yyval.ruleTerm) = new RuleTerm(NULL, 0); }
#line 1654 "rules.tab.c"
    break;

  case 18: /* rule: maybename '{' '/' STRINGSYM '/' ARROWSYM @4 rhslist '}'  */
#line 199 "rules.y"
          {
	    tempElements[0].Init(Element::Regexp, (yyvsp[-5].string), NULL, NULL, ExactlyOne);
	    RuleTerm *r = (yyvsp[-2].ruleTerm);
	    Expr *corr = r->GetCorr();
	    if (corr && corr->semtype == Interval) corr = corr->c.op.Left();
	    if (corr && (corr->semtype != String || corr->type != Expr::Leaf)) {
	      ParseError("Corr-instruktionen i en teckenmatchningsregel måste vara en textsträng");
	      corr = NULL;
	    }
	    ruleSet.Add(new RegExpRule(NewElements(tempElements, 1), (yyvsp[-5].string),
				       (yyvsp[-8].identifier), r->GetMark(), 
				       corr ? corr->c.string : NULL,
				       r->GetJump(), r->GetInfo(),
				       r->GetAction(),
				       r->GetDetect(), r->GetAccept()));
	    IdEntry::NewScope();
	  }
#line 1676 "rules.tab.c"
    break;

  case 19: /* rule: maybename '{' '/' error '}'  */
#line 216 "rules.y"
                                      { ParseError("Fel i reguljärt uttrycks-regel"); }
#line 1682 "rules.tab.c"
    break;

  case 20: /* rule: maybename '{' error '}'  */
#line 217 "rules.y"
                                  { ParseError("Fel syntax i regelns högerled"); }
#line 1688 "rules.tab.c"
    break;

  case 21: /* newscope: %empty  */
#line 220 "rules.y"
           { IdEntry::NewScope(); }
#line 1694 "rules.tab.c"
    break;

  case 22: /* maybename: %empty  */
#line 223 "rules.y"
                         { (yyval.identifier) = NULL; }
#line 1700 "rules.tab.c"
    break;

  case 23: /* maybename: UNDEFIDENTSYM ':' maybename  */
#line 224 "rules.y"
                                      { (yyvsp[-2].identifier)->IntoGlobalTable(IdEntry::LabelId);
					(yyvsp[-2].identifier)->u.ruleNo = ruleSet.NRules();
					(yyval.identifier) = (yyvsp[0].identifier); }
#line 1708 "rules.tab.c"
    break;

  case 24: /* maybename: LABELIDENTSYM ':' maybename  */
#line 227 "rules.y"
                                      { if ((yyvsp[-2].identifier)->u.ruleNo >= 0)
					  ParseErrorArg("Läget %s är redan definierat", (yyvsp[-2].identifier)->name);
					else (yyvsp[-2].identifier)->u.ruleNo = ruleSet.NRules();
					(yyval.identifier) = (yyvsp[0].identifier); }
#line 1717 "rules.tab.c"
    break;

  case 25: /* maybename: UNDEFIDENTSYMAT  */
#line 231 "rules.y"
                          { (yyvsp[0].identifier)->IntoGlobalTable(IdEntry::RuleId); 
			      (yyvsp[0].identifier)->u.ruleNo = ruleSet.NRules();
			      (yyval.identifier) = (yyvsp[0].identifier); }
#line 1725 "rules.tab.c"
    break;

  case 26: /* maybename: RULEIDENTSYMAT  */
#line 234 "rules.y"
                          { if ((yyvsp[0].identifier)->u.ruleNo >= 0) {
			        ParseError("@ ska föregås av ett inte tidigare definierat namn"); (yyval.identifier) = NULL; }
			      else { (yyvsp[0].identifier)->u.ruleNo = ruleSet.NRules(); (yyval.identifier) = (yyvsp[0].identifier); }}
#line 1733 "rules.tab.c"
    break;

  case 27: /* maybename: '@'  */
#line 237 "rules.y"
              { ParseError("@ ska föregås av ett inte tidigare definierat namn"); (yyval.identifier) = NULL; }
#line 1739 "rules.tab.c"
    break;

  case 28: /* altrules: altrule  */
#line 241 "rules.y"
                  { firstAltRule = (yyval.ruleTerm) = (yyvsp[0].ruleTerm); }
#line 1745 "rules.tab.c"
    break;

  case 29: /* altrules: altrules ';' newscope altrule  */
#line 242 "rules.y"
                                        { (yyvsp[-3].ruleTerm)->SetNext((yyvsp[0].ruleTerm)); (yyval.ruleTerm) = (yyvsp[0].ruleTerm); }
#line 1751 "rules.tab.c"
    break;

  case 30: /* $@5: %empty  */
#line 243 "rules.y"
                    { ParseError("Fel syntax i regelns högerled"); }
#line 1757 "rules.tab.c"
    break;

  case 31: /* altrules: error ';' $@5 altrule  */
#line 244 "rules.y"
                            { (yyval.ruleTerm) = (yyvsp[0].ruleTerm); }
#line 1763 "rules.tab.c"
    break;

  case 32: /* @6: %empty  */
#line 247 "rules.y"
                       { currentElementName = NULL; 
                         (yyval.ruleTerm) = new RuleTerm((yyvsp[-1].element), currentNoOfElement, endLeftContext, beginRightContext); }
#line 1770 "rules.tab.c"
    break;

  case 33: /* altrule: lhs ARROWSYM @6 rhslist  */
#line 249 "rules.y"
                  { (yyval.ruleTerm) = (yyvsp[-1].ruleTerm); currentNoOfElement = 0; 
		    if (!(yyval.ruleTerm)->IsHelp() && (endLeftContext >= 0 || beginRightContext >= 0))
		      ParseError("Kontext får bara förekomma i hjälpregler.");
	  	    endLeftContext = beginRightContext = -1;
     	            if (!(yyval.ruleTerm)->GetAction()) ParseError("Ingen åtgärdsdel i högerledet."); }
#line 1780 "rules.tab.c"
    break;

  case 34: /* @7: %empty  */
#line 254 "rules.y"
                         { ParseError("Fel syntax i regelns vänsterled");
                           (yyval.ruleTerm) = new RuleTerm(NULL, currentNoOfElement, endLeftContext, beginRightContext); }
#line 1787 "rules.tab.c"
    break;

  case 35: /* altrule: error ARROWSYM @7 rhslist  */
#line 257 "rules.y"
                    { currentNoOfElement = 0; 
	  	      endLeftContext = beginRightContext = -1; }
#line 1794 "rules.tab.c"
    break;

  case 38: /* rhs: MARKSYM '(' setmark mark  */
#line 265 "rules.y"
                                   { (yyvsp[(-1) - (4)].ruleTerm)->SetMark((yyvsp[0].node)->semtype == Interval ?
                                                            (yyvsp[0].node) : new Expr(' ', Interval, (yyvsp[0].node), NULL) ); }
#line 1801 "rules.tab.c"
    break;

  case 39: /* rhs: CORRSYM '(' setcorr corr  */
#line 267 "rules.y"
                                   { (yyvsp[(-1) - (4)].ruleTerm)->SetCorr((yyvsp[0].node)); }
#line 1807 "rules.tab.c"
    break;

  case 40: /* rhs: JUMPSYM '(' setjump jump  */
#line 268 "rules.y"
                                   { (yyvsp[(-1) - (4)].ruleTerm)->SetJump((yyvsp[0].gotoentry)); }
#line 1813 "rules.tab.c"
    break;

  case 41: /* rhs: INFOSYM '(' setinfo info  */
#line 269 "rules.y"
                                   { (yyvsp[(-1) - (4)].ruleTerm)->SetInfo((yyvsp[0].node)); }
#line 1819 "rules.tab.c"
    break;

  case 42: /* rhs: ACTIONSYM '(' setaction action  */
#line 270 "rules.y"
                                         { (yyvsp[(-1) - (4)].ruleTerm)->SetAction((yyvsp[0].node)); }
#line 1825 "rules.tab.c"
    break;

  case 43: /* rhs: DETECTSYM '(' STRINGSYM ')'  */
#line 271 "rules.y"
                                      { if (xCheckAccept) (yyvsp[(-1) - (4)].ruleTerm)->SetDetect((yyvsp[-1].string)); }
#line 1831 "rules.tab.c"
    break;

  case 44: /* rhs: ACCEPTSYM '(' STRINGSYM ')'  */
#line 272 "rules.y"
                                      { if (xCheckAccept) (yyvsp[(-1) - (4)].ruleTerm)->SetAccept((yyvsp[-1].string)); }
#line 1837 "rules.tab.c"
    break;

  case 45: /* rhs: LINKSYM '(' STRINGSYM STRINGSYM ')'  */
#line 273 "rules.y"
                                              { (yyvsp[(-1) - (5)].ruleTerm)->SetLink((yyvsp[-2].string), (yyvsp[-1].string)); }
#line 1843 "rules.tab.c"
    break;

  case 46: /* rhs: error ')'  */
#line 274 "rules.y"
                    { ParseError("Felaktigt fält i högerledet."); }
#line 1849 "rules.tab.c"
    break;

  case 47: /* setmark: %empty  */
#line 277 "rules.y"
          { exprUse = InMark; }
#line 1855 "rules.tab.c"
    break;

  case 48: /* setcorr: %empty  */
#line 280 "rules.y"
          { exprUse = InCorr; }
#line 1861 "rules.tab.c"
    break;

  case 49: /* setjump: %empty  */
#line 283 "rules.y"
          { exprUse = InJump; }
#line 1867 "rules.tab.c"
    break;

  case 50: /* setinfo: %empty  */
#line 286 "rules.y"
          { exprUse = InInfo; }
#line 1873 "rules.tab.c"
    break;

  case 51: /* setaction: %empty  */
#line 289 "rules.y"
            { exprUse = InAction; }
#line 1879 "rules.tab.c"
    break;

  case 52: /* gbglhslist: lhs  */
#line 292 "rules.y"
                      { firstlhs = (yyval.ruleTerm) = new RuleTerm((yyvsp[0].element), currentNoOfElement); 
		if (endLeftContext >= 0 || beginRightContext >= 0) ParseError("Kontextgränser kan inte ges i denna typ av regel.");
                currentNoOfElement = 0;
		endLeftContext = beginRightContext = -1; }
#line 1888 "rules.tab.c"
    break;

  case 53: /* gbglhslist: gbglhslist ';' lhs  */
#line 296 "rules.y"
                             {
		(yyvsp[-2].ruleTerm) = (yyval.ruleTerm) = new RuleTerm((yyvsp[0].element), currentNoOfElement); 
		if (endLeftContext >= 0 || beginRightContext >= 0) ParseError("Kontextgränser kan inte ges i denna typ av regel.");
                currentNoOfElement = 0;
		endLeftContext = beginRightContext = -1; }
#line 1898 "rules.tab.c"
    break;

  case 54: /* lhs: elements  */
#line 303 "rules.y"
                   { (yyval.element) = NewElements(tempElements, currentNoOfElement); }
#line 1904 "rules.tab.c"
    break;

  case 57: /* $@8: %empty  */
#line 308 "rules.y"
                               { ParseError("Kommatecken utelämnat mellan element i vänsterledet"); }
#line 1910 "rules.tab.c"
    break;

  case 59: /* elements: error ','  */
#line 310 "rules.y"
                    { ParseError("Fel i elementspecifikationen"); }
#line 1916 "rules.tab.c"
    break;

  case 60: /* $@9: %empty  */
#line 314 "rules.y"
          { tempElements[currentNoOfElement].Init(Element::Word, NULL, (yyvsp[0].identifier), NULL, ExactlyOne);
	  }
#line 1923 "rules.tab.c"
    break;

  case 61: /* $@10: %empty  */
#line 317 "rules.y"
          { if ((yyvsp[-1].node)->semtype != Boolean) ParseError("Matchningskravsuttrycket måste vara ett booleskt uttryck"); }
#line 1929 "rules.tab.c"
    break;

  case 62: /* element: elementname $@9 maybeexpr ')' $@10 maybeocc  */
#line 319 "rules.y"
            {
	      if (currentNoOfElement >= MAXNOOFELEMENTS) {
		ParseError("För många element i samma regel.");
	      } else {
		if ((yyvsp[-5].identifier)->type == IdEntry::RuleElementId && // HelpRule
		    ((yyvsp[0].integer) != ExactlyOne && (yyvsp[0].integer) != 1 && (yyvsp[0].integer) != ZeroOrOne)) {
		  ParseError("Bara ? får förekomma som antal förekomster i hjälpregel.");
		}
		tempElements[currentNoOfElement].Init(Element::Word, NULL, (yyvsp[-5].identifier), (yyvsp[-3].node), (yyvsp[0].integer));
		currentNoOfElement++; // måste göras efter anropet till Init
	      }
	    }
#line 1946 "rules.tab.c"
    break;

  case 63: /* $@11: %empty  */
#line 332 "rules.y"
            { ParseError("Fel i matchningskravsuttrycket"); }
#line 1952 "rules.tab.c"
    break;

  case 64: /* element: elementname error ')' $@11 maybeocc  */
#line 333 "rules.y"
                   {}
#line 1958 "rules.tab.c"
    break;

  case 65: /* element: ENDLEFTCONTEXTSYM  */
#line 334 "rules.y"
                            { 
               if (endLeftContext >= 0) ParseError("Flera ENDLEFTCONTEXT i samma vänsterled.");
	       else if (beginRightContext >= 0) ParseError("ENDLEFTCONTEXT måste komma före BEGINRIGHTCONTEXT.");
	       else endLeftContext = currentNoOfElement;
          }
#line 1968 "rules.tab.c"
    break;

  case 66: /* element: BEGINRIGHTCONTEXTSYM  */
#line 339 "rules.y"
                               { 
               if (beginRightContext >= 0) ParseError("Flera BEGINRIGHTCONTEXT i samma vänsterled.");
	       else beginRightContext = currentNoOfElement;
          }
#line 1977 "rules.tab.c"
    break;

  case 67: /* elementname: UNDEFIDENTSYM '('  */
#line 345 "rules.y"
                                { (yyvsp[-1].identifier)->IntoLocalTable();
			          currentElementName = (yyvsp[-1].identifier)->name; 
				  exprUse = InLHS; 
				  (yyval.identifier) = (yyvsp[-1].identifier); }
#line 1986 "rules.tab.c"
    break;

  case 68: /* elementname: '(' helprule ')' '('  */
#line 349 "rules.y"
                               { (yyvsp[-2].identifier)->IntoLocalTable();
				 (yyvsp[-2].identifier)->type = IdEntry::RuleElementId;
			         currentElementName = (yyvsp[-2].identifier)->name; 
				 exprUse = InLHS;
				 (yyval.identifier) = (yyvsp[-2].identifier); }
#line 1996 "rules.tab.c"
    break;

  case 69: /* elementname: '(' error ')' '('  */
#line 354 "rules.y"
                            { ParseError("En hjälpregel måste anges inom (...)"); (yyval.identifier) = NULL; }
#line 2002 "rules.tab.c"
    break;

  case 70: /* elementname: error '('  */
#line 355 "rules.y"
                    { ParseError("Elementets namn måste vara ett ännu inte definierat namn"); (yyval.identifier) = NULL; }
#line 2008 "rules.tab.c"
    break;

  case 71: /* helprule: UNDEFIDENTSYM  */
#line 358 "rules.y"
                         { (yyvsp[0].identifier)->IntoGlobalTable(IdEntry::RuleId);
			   (yyvsp[0].identifier)->u.ruleNo = -1; 
			   (yyval.identifier) = new IdEntry((yyvsp[0].identifier)->name); // jb: who is responsible for the mem?
			   (yyval.identifier)->u.re.ruleId = (yyvsp[0].identifier);
			 }
#line 2018 "rules.tab.c"
    break;

  case 72: /* helprule: RULEIDENTSYM  */
#line 363 "rules.y"
                         {
			   (yyval.identifier) = new IdEntry((yyvsp[0].identifier)->name);
			   (yyval.identifier)->u.re.ruleId = (yyvsp[0].identifier);
			 }
#line 2027 "rules.tab.c"
    break;

  case 73: /* helprule: RULEIDENTSYMAT  */
#line 367 "rules.y"
                         {
			   (yyval.identifier) = new IdEntry((yyvsp[0].identifier)->name);
			   (yyval.identifier)->u.re.ruleId = (yyvsp[0].identifier);
			 }
#line 2036 "rules.tab.c"
    break;

  case 74: /* helprule: UNDEFIDENTSYM '/' UNDEFIDENTSYM  */
#line 371 "rules.y"
                                          {
			   (yyvsp[-2].identifier)->IntoGlobalTable(IdEntry::RuleId);
			   (yyvsp[-2].identifier)->u.ruleNo = -1; 
			   (yyval.identifier) = (yyvsp[0].identifier);
			   (yyval.identifier)->u.re.ruleId = (yyvsp[-2].identifier);
			 }
#line 2047 "rules.tab.c"
    break;

  case 75: /* helprule: RULEIDENTSYM '/' UNDEFIDENTSYM  */
#line 377 "rules.y"
                                         { 
			   (yyval.identifier) = (yyvsp[0].identifier);
			   (yyval.identifier)->u.re.ruleId = (yyvsp[-2].identifier);
			 }
#line 2056 "rules.tab.c"
    break;

  case 76: /* helprule: RULEIDENTSYMAT '/' UNDEFIDENTSYM  */
#line 381 "rules.y"
                                           { 
			   (yyval.identifier) = (yyvsp[0].identifier);
			   (yyval.identifier)->u.re.ruleId = (yyvsp[-2].identifier);
			 }
#line 2065 "rules.tab.c"
    break;

  case 77: /* maybeocc: %empty  */
#line 387 "rules.y"
                         { (yyval.integer) = ExactlyOne; }
#line 2071 "rules.tab.c"
    break;

  case 78: /* maybeocc: INTEGERSYM  */
#line 388 "rules.y"
                     { if ((yyvsp[0].integer) == 0) 
	                 ParseError("noll förekomster av ett element är orimligt");
	               (yyval.integer) = (yyvsp[0].integer); }
#line 2079 "rules.tab.c"
    break;

  case 79: /* maybeocc: '*'  */
#line 391 "rules.y"
              { (yyval.integer) = ZeroOrMore; }
#line 2085 "rules.tab.c"
    break;

  case 80: /* maybeocc: '+'  */
#line 392 "rules.y"
              { (yyval.integer) = OneOrMore; }
#line 2091 "rules.tab.c"
    break;

  case 81: /* maybeocc: '?'  */
#line 393 "rules.y"
              { (yyval.integer) = ZeroOrOne; }
#line 2097 "rules.tab.c"
    break;

  case 83: /* mark: error ')'  */
#line 397 "rules.y"
                    { ParseError("Fel i högerledets märkningsdel"); (yyval.node) = NULL; }
#line 2103 "rules.tab.c"
    break;

  case 84: /* corr: ')'  */
#line 400 "rules.y"
              { (yyval.node) = NULL; }
#line 2109 "rules.tab.c"
    break;

  case 85: /* corr: exprseq ')'  */
#line 401 "rules.y"
                      { if ((yyvsp[-1].node)->semtype != Interval) (yyval.node) = new Expr(' ', Interval, (yyvsp[-1].node), NULL); }
#line 2115 "rules.tab.c"
    break;

  case 86: /* corr: error ')'  */
#line 402 "rules.y"
                    { ParseError("Fel i högerledets korrektionsdel"); (yyval.node) = NULL; }
#line 2121 "rules.tab.c"
    break;

  case 87: /* jump: ')'  */
#line 405 "rules.y"
              { (yyval.gotoentry) = NULL; }
#line 2127 "rules.tab.c"
    break;

  case 88: /* jump: UNDEFIDENTSYM ')'  */
#line 406 "rules.y"
                            { (yyvsp[-1].identifier)->IntoGlobalTable(IdEntry::LabelId);
					(yyvsp[-1].identifier)->u.ruleNo = -1;
					(yyval.gotoentry) = new GotoEntry((yyvsp[-1].identifier), NULL); }
#line 2135 "rules.tab.c"
    break;

  case 89: /* jump: LABELIDENTSYM ')'  */
#line 409 "rules.y"
                            {
		if ((yyvsp[-1].identifier)->u.ruleNo >= 0 && (yyvsp[-1].identifier)->u.ruleNo <= ruleSet.NRules())
		  ParseError("Förbjudet att hoppa bakåt i regelsamlingen");
		(yyval.gotoentry) = new GotoEntry((yyvsp[-1].identifier), NULL); }
#line 2144 "rules.tab.c"
    break;

  case 90: /* jump: UNDEFIDENTSYM ',' expr ')'  */
#line 413 "rules.y"
                                     { 
	                                (yyvsp[-3].identifier)->IntoGlobalTable(IdEntry::LabelId);
					(yyvsp[-3].identifier)->u.ruleNo = -1;
					if ((yyvsp[-1].node)->semtype != Integer)
					  ParseError("Andra parametern till GOTO TOKEN måste vara ett heltal.");
					(yyval.gotoentry) = new GotoEntry((yyvsp[-3].identifier), (yyvsp[-1].node)); }
#line 2155 "rules.tab.c"
    break;

  case 91: /* jump: LABELIDENTSYM ',' expr ')'  */
#line 419 "rules.y"
                                     {
	        if ((yyvsp[-1].node)->semtype != Integer)
		  ParseError("Andra parametern till GOTO TOKEN måste vara ett heltal.");
		(yyval.gotoentry) = new GotoEntry((yyvsp[-3].identifier), (yyvsp[-1].node)); }
#line 2164 "rules.tab.c"
    break;

  case 92: /* jump: error ')'  */
#line 423 "rules.y"
                    { ParseError("Fel i högerledets hoppdel"); (yyval.gotoentry) = NULL; }
#line 2170 "rules.tab.c"
    break;

  case 93: /* info: ')'  */
#line 426 "rules.y"
               { (yyval.node) = NULL; }
#line 2176 "rules.tab.c"
    break;

  case 95: /* info: error ')'  */
#line 428 "rules.y"
                    { ParseError("Fel i högerledets kommentardel"); (yyval.node) = NULL; }
#line 2182 "rules.tab.c"
    break;

  case 96: /* action: ')'  */
#line 431 "rules.y"
              { (yyval.node) = NULL; }
#line 2188 "rules.tab.c"
    break;

  case 97: /* action: actionident ')'  */
#line 432 "rules.y"
                          { (yyval.node) = new Expr((yyvsp[-1].integer), NoType, NULL, NULL); }
#line 2194 "rules.tab.c"
    break;

  case 98: /* action: actionident ',' args ')'  */
#line 433 "rules.y"
                                   { if ((yyvsp[-3].integer) != HELPIDENTSYM && (yyvsp[-3].integer) != TAGIDENTSYM) 
ParseError("Argument kan bara ges till åtgärderna HJÄLP och TAGGNING");
                                 (yyval.node) = new Expr((yyvsp[-3].integer), NoType, (yyvsp[-1].node), NULL); }
#line 2202 "rules.tab.c"
    break;

  case 99: /* action: error ')'  */
#line 436 "rules.y"
                    { ParseError("Fel i högerledets åtgärdsdel"); (yyval.node) = NULL; }
#line 2208 "rules.tab.c"
    break;

  case 100: /* actionident: TAGIDENTSYM  */
#line 439 "rules.y"
                          { (yyval.integer) = TAGIDENTSYM; }
#line 2214 "rules.tab.c"
    break;

  case 101: /* actionident: CHECKIDENTSYM  */
#line 440 "rules.y"
                          { (yyval.integer) = CHECKIDENTSYM; }
#line 2220 "rules.tab.c"
    break;

  case 102: /* actionident: LOOKUPIDENTSYM  */
#line 441 "rules.y"
                          { (yyval.integer) = LOOKUPIDENTSYM; }
#line 2226 "rules.tab.c"
    break;

  case 103: /* actionident: EDITIDENTSYM  */
#line 442 "rules.y"
                          { (yyval.integer) = EDITIDENTSYM; }
#line 2232 "rules.tab.c"
    break;

  case 104: /* actionident: HELPIDENTSYM  */
#line 443 "rules.y"
                          { (yyval.integer) = HELPIDENTSYM; }
#line 2238 "rules.tab.c"
    break;

  case 105: /* actionident: ACCEPTIDENTSYM  */
#line 444 "rules.y"
                          { (yyval.integer) = ACCEPTIDENTSYM; }
#line 2244 "rules.tab.c"
    break;

  case 106: /* maybeexpr: %empty  */
#line 447 "rules.y"
                         { (yyval.node) = constantTrue; }
#line 2250 "rules.tab.c"
    break;

  case 108: /* expr: REALSYM  */
#line 451 "rules.y"
                             { (yyval.node) = new Expr(Expr::Leaf, Real);
                               (yyval.node)->c.real = (yyvsp[0].real); }
#line 2257 "rules.tab.c"
    break;

  case 109: /* expr: INTEGERSYM  */
#line 453 "rules.y"
                             { (yyval.node) = new Expr(Expr::Leaf, Integer);
                               (yyval.node)->c.integer = (yyvsp[0].integer); }
#line 2264 "rules.tab.c"
    break;

  case 110: /* expr: STRINGSYM  */
#line 455 "rules.y"
                             { (yyval.node) = new Expr(Expr::Leaf, String);
                               (yyval.node)->c.string = (yyvsp[0].string); }
#line 2271 "rules.tab.c"
    break;

  case 111: /* expr: VARIDENTSYM  */
#line 457 "rules.y"
                             { (yyval.node) = new Expr(Expr::Leaf, Variable);
                               (yyval.node)->c.id = (yyvsp[0].identifier); }
#line 2278 "rules.tab.c"
    break;

  case 112: /* expr: RULEELEMENTIDENTSYM  */
#line 459 "rules.y"
                               { (yyval.node) = new Expr(Expr::Leaf, Variable);
                                 (yyval.node)->c.id = (yyvsp[0].identifier); }
#line 2285 "rules.tab.c"
    break;

  case 114: /* expr: FUNCIDENTSYM arglist  */
#line 462 "rules.y"
                               { Expr *p = new Expr(Expr::Function, (yyvsp[-1].methodorfunction)->semtype);
                                 p->c.method.id = (yyvsp[-1].methodorfunction);
                                 p->c.method.actuals = (yyvsp[0].node);
				 (yyvsp[-1].methodorfunction)->ParametersOK((yyvsp[0].node));
				 (yyval.node) = p; }
#line 2295 "rules.tab.c"
    break;

  case 115: /* expr: CONSTIDENTSYM  */
#line 467 "rules.y"
                             { (yyval.node) = (yyvsp[0].identifier)->u.expr; }
#line 2301 "rules.tab.c"
    break;

  case 116: /* expr: UNDEFIDENTSYM  */
#line 468 "rules.y"
                             { ParseErrorArg("Namnet %s är inte definierat", (yyvsp[0].identifier)->name); }
#line 2307 "rules.tab.c"
    break;

  case 117: /* expr: expr '.' methodorattribute  */
#line 469 "rules.y"
                                     { (yyval.node) = DotExpr((yyvsp[-2].node), (yyvsp[0].node)); }
#line 2313 "rules.tab.c"
    break;

  case 118: /* expr: expr '.' error  */
#line 470 "rules.y"
                             { ParseError("Okänd metod eller attribut efter ."); }
#line 2319 "rules.tab.c"
    break;

  case 119: /* expr: expr '+' expr  */
#line 471 "rules.y"
                             { (yyval.node) = new Expr('+', (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2325 "rules.tab.c"
    break;

  case 120: /* expr: expr '-' expr  */
#line 472 "rules.y"
                             { if ((yyvsp[-2].node)->semtype == Variable && 
				   (yyvsp[0].node)->semtype == Variable && 
				   (exprUse == InMark || exprUse == InCorr)) {
				 (yyval.node) = new Expr('-', Interval, (yyvsp[-2].node), (yyvsp[0].node));
			       } else {
				 if (!IsNumber((yyvsp[-2].node)->semtype) ||
				     !IsNumber((yyvsp[0].node)->semtype)) {
				   ParseError("Båda operanderna till - ska vara tal eller variabler.");
			         }
			         (yyval.node) = new Expr('-', HighestType((yyvsp[-2].node)->semtype,
				             (yyvsp[0].node)->semtype), (yyvsp[-2].node), (yyvsp[0].node)); }
			       }
#line 2342 "rules.tab.c"
    break;

  case 121: /* expr: expr '=' expr  */
#line 484 "rules.y"
                             { if (!Compatible((yyvsp[-2].node), (yyvsp[0].node))) 
				 ParseError("Båda operanderna till = måste ha samma typ.");
			       (yyval.node) = new Expr('=', Boolean, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2350 "rules.tab.c"
    break;

  case 122: /* expr: expr '~' expr  */
#line 487 "rules.y"
                             { if (((yyvsp[-2].node)->semtype == String || (yyvsp[-2].node)->semtype == Variable)
				   && (yyvsp[0].node)->semtype == String) {
				 if ((yyvsp[0].node)->type == Expr::Leaf) {
				   if (CompileRegexp((yyvsp[0].node)->c)) (yyvsp[0].node)->semtype = Regexp;
				   else ParseErrorArg("Felaktigt reguljärt uttryck: %s", (yyvsp[0].node)->c.string);
			         }
			       } else {
				 ParseError("Båda operanderna till ~ måste ha strängtyp.");
			       }
			       (yyval.node) = new Expr('~', Boolean, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2365 "rules.tab.c"
    break;

  case 123: /* expr: expr NESYM expr  */
#line 497 "rules.y"
                               { if (!Compatible((yyvsp[-2].node), (yyvsp[0].node)))
	                           ParseError("Båda operanderna till != måste ha samma typ.");
 			         (yyval.node) = new Expr(NESYM, Boolean, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2373 "rules.tab.c"
    break;

  case 124: /* expr: expr LESYM expr  */
#line 500 "rules.y"
                             { (yyval.node) = new Expr(LESYM, (yyvsp[-2].node), (yyvsp[0].node)); 
			       (yyval.node)->semtype = Boolean; }
#line 2380 "rules.tab.c"
    break;

  case 125: /* expr: expr GESYM expr  */
#line 502 "rules.y"
                             { (yyval.node) = new Expr(GESYM, (yyvsp[-2].node), (yyvsp[0].node));
			       (yyval.node)->semtype = Boolean; }
#line 2387 "rules.tab.c"
    break;

  case 126: /* expr: expr '<' expr  */
#line 504 "rules.y"
                             { (yyval.node) = new Expr('<', (yyvsp[-2].node), (yyvsp[0].node));
			       (yyval.node)->semtype = Boolean; }
#line 2394 "rules.tab.c"
    break;

  case 127: /* expr: expr '>' expr  */
#line 506 "rules.y"
                             { (yyval.node) = new Expr('>', (yyvsp[-2].node), (yyvsp[0].node));
			       (yyval.node)->semtype = Boolean; }
#line 2401 "rules.tab.c"
    break;

  case 128: /* expr: expr '&' expr  */
#line 508 "rules.y"
                             { if (!((yyvsp[-2].node)->semtype == Boolean &&
				     (yyvsp[0].node)->semtype == Boolean)) {
				 ParseError("Båda operanderna till & måste vara booleska."); }
			       (yyval.node) = new Expr('&', Boolean, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2410 "rules.tab.c"
    break;

  case 129: /* expr: expr '|' expr  */
#line 512 "rules.y"
                             { if (!((yyvsp[-2].node)->semtype == Boolean &&
				     (yyvsp[0].node)->semtype == Boolean)) {
				 ParseError("Båda operanderna till | måste vara booleska."); }
			       (yyval.node) = new Expr('|', Boolean, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2419 "rules.tab.c"
    break;

  case 130: /* expr: expr ASSIGNSYM expr  */
#line 516 "rules.y"
                              { (yyval.node) = AssignExpr((yyvsp[-2].node), (yyvsp[0].node)); }
#line 2425 "rules.tab.c"
    break;

  case 131: /* expr: '!' expr  */
#line 517 "rules.y"
                             { if ((yyvsp[0].node)->semtype != Boolean) {
				 ParseError("Operanden till ! måste vara boolesk."); }
			       (yyval.node) = new Expr('!', Boolean, (yyvsp[0].node), NULL); }
#line 2433 "rules.tab.c"
    break;

  case 132: /* expr: '(' '-' expr ')'  */
#line 520 "rules.y"
                             { if (!(IsNumber((yyvsp[-1].node)->semtype))) {
				 ParseError("Operanden till - måste vara ett tal."); }
			       (yyval.node) = new Expr(NEG, (yyvsp[-1].node)->semtype, (yyvsp[-1].node), NULL); }
#line 2441 "rules.tab.c"
    break;

  case 133: /* expr: '(' expr ')'  */
#line 523 "rules.y"
                             { (yyval.node) = (yyvsp[-1].node); }
#line 2447 "rules.tab.c"
    break;

  case 134: /* expr: expr '[' expr ']'  */
#line 524 "rules.y"
                             { if (!((yyvsp[-3].node)->semtype == Variable &&
				     (yyvsp[-1].node)->semtype == Integer)
				   || (yyvsp[-3].node)->c.id->Elt(tempElements) == NULL) {
				 ParseError("Felaktiga operander till arrayindexeringen."); }
				else if (!((yyvsp[-3].node)->c.id->Elt(tempElements)->MultiOcc() ||
					  (yyvsp[-3].node)->c.id->type == IdEntry::RuleElementId)) {
	     			 ParseError("Bara hjälpregelelement och element med + eller * kan indexeras."); }
			       (yyval.node) = new Expr('[', Variable, (yyvsp[-3].node), (yyvsp[-1].node)); }
#line 2460 "rules.tab.c"
    break;

  case 135: /* expr: PROBSYM '(' expr ',' expr ')'  */
#line 532 "rules.y"
                                        { if (!(IsNumber((yyvsp[-3].node)->semtype) &&
				     (yyvsp[-1].node)->semtype == Boolean)) {
				 ParseError("Felaktiga parametrar till P-funktionen."); }
			       (yyval.node) = new Expr(PROBSYM, Boolean, (yyvsp[-3].node), (yyvsp[-1].node)); }
#line 2469 "rules.tab.c"
    break;

  case 136: /* expr: FORALLSYM '(' expr ')'  */
#line 536 "rules.y"
                                 { if ((yyvsp[-1].node)->semtype != Boolean) {
				 ParseError("Felaktig parameter till FÖR ALLA-funktionen."); }
				   (yyval.node) = new Expr(PROBSYM, Boolean, constantAlmostOne, (yyvsp[-1].node)); }
#line 2477 "rules.tab.c"
    break;

  case 137: /* expr: EXISTSYM '(' expr ')'  */
#line 539 "rules.y"
                                { if ((yyvsp[-1].node)->semtype != Boolean) {
				    ParseError("Felaktig parameter till EXISTERAR-funktionen."); }
				  (yyval.node) = new Expr(PROBSYM, Boolean, constantAlmostZero, (yyvsp[-1].node)); }
#line 2485 "rules.tab.c"
    break;

  case 138: /* $@12: %empty  */
#line 542 "rules.y"
                             { if ((yyvsp[-1].node)->semtype != Boolean)
				 ParseError("Ett villkor väntades efter IF."); }
#line 2492 "rules.tab.c"
    break;

  case 139: /* expr: IFSYM expr THENSYM $@12 exprseq ELSESYM exprseq ENDSYM  */
#line 544 "rules.y"
                                         { (yyval.node) = IfExpr((yyvsp[-6].node), (yyvsp[-3].node), (yyvsp[-1].node)); }
#line 2498 "rules.tab.c"
    break;

  case 140: /* expr: IFSYM error ENDSYM  */
#line 545 "rules.y"
                             { ParseError("Fel i IF-sats."); }
#line 2504 "rules.tab.c"
    break;

  case 141: /* methodorattribute: ATTRIDENTSYM  */
#line 549 "rules.y"
                             { Expr *p = new Expr(Expr::Attribute, (yyvsp[0].identifier)->semtype);
                               p->c.id = (yyvsp[0].identifier);
			       if (IsFeature((yyvsp[0].identifier)->semtype)) 
				 p->featureClass = (yyvsp[0].identifier)->u.featureClass;
			       (yyval.node) = p; }
#line 2514 "rules.tab.c"
    break;

  case 142: /* methodorattribute: METHIDENTSYM arglist  */
#line 554 "rules.y"
                               { Expr *p = new Expr(Expr::Method, (yyvsp[-1].methodorfunction)->semtype);
                                 p->c.method.id = (yyvsp[-1].methodorfunction);
                                 p->c.method.actuals = (yyvsp[0].node);
				 (yyvsp[-1].methodorfunction)->ParametersOK((yyvsp[0].node));
			         if (IsFeature((yyvsp[-1].methodorfunction)->semtype)) 
				   p->featureClass = (yyvsp[-1].methodorfunction)->featureClass;
				 (yyval.node) = p; }
#line 2526 "rules.tab.c"
    break;

  case 143: /* arglist: '(' args ')'  */
#line 563 "rules.y"
                       { (yyval.node) = (yyvsp[-1].node); }
#line 2532 "rules.tab.c"
    break;

  case 144: /* arglist: '(' ')'  */
#line 564 "rules.y"
                  { (yyval.node) = NULL; }
#line 2538 "rules.tab.c"
    break;

  case 145: /* arglist: error ')'  */
#line 565 "rules.y"
                       { ParseError("Fel i parameterlistan"); (yyval.node) = NULL; }
#line 2544 "rules.tab.c"
    break;

  case 146: /* args: expr  */
#line 568 "rules.y"
                        { (yyval.node) = new Expr(',', NoType, (yyvsp[0].node), NULL); }
#line 2550 "rules.tab.c"
    break;

  case 147: /* args: expr ',' args  */
#line 569 "rules.y"
                        { (yyval.node) = new Expr(',', NoType, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2556 "rules.tab.c"
    break;

  case 149: /* exprseq: expr exprseq  */
#line 573 "rules.y"
                       { if (exprUse != InMark && exprUse != InInfo && exprUse != InCorr)
				 ParseError("Flera uttryck kan inte radas upp");
			       else if (((yyvsp[-1].node)->semtype != Variable &&
                                         (yyvsp[-1].node)->semtype != CorrT && 
				         (yyvsp[-1].node)->semtype != Interval &&
				         (yyvsp[-1].node)->semtype != String) ||
				        ((yyvsp[0].node)->semtype != Variable && 
				         (yyvsp[0].node)->semtype != Interval &&
                                         (yyvsp[0].node)->semtype != CorrT && 
				         (yyvsp[0].node)->semtype != String))
				 ParseError("Bara variabler och texter kan användas här");
			       (yyval.node) = new Expr(' ', Interval, (yyvsp[-1].node), (yyvsp[0].node));
			     }
#line 2574 "rules.tab.c"
    break;


#line 2578 "rules.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 587 "rules.y"


#include "lex.yy.c"

	/* Semantic functions used as actions above */
static Expr *DotExpr(Expr *left, Expr *right) {
  if (left->semtype != Variable &&
      left->semtype != LexVariable &&
      left->semtype != String) {
    ParseError("En variabel måste ges före .");
    return NULL;
  }
  if (currentElementName && 
      left->type==Expr::Leaf && left->semtype == Variable &&
      strcmp(left->c.id->Name(), currentElementName) == 0) {
    errorLine = line;
    ParseWarningArg("Varning: %s är aktuell variabel och behöver inte anges i punkt-uttrycket\n", currentElementName);
    return right;
  }
  enum semantictype semtype = right->semtype;
  if (semtype == LexVariable) semtype = Variable;
  Expr *p = new Expr('.', semtype, left, right); 
  if (IsFeature(right->semtype))
    p->featureClass = right->GetFeatureClass();
  return p;
}

static Expr *AssignExpr(Expr *lhs, Expr *rhs) {
  if (exprUse != InCorr && exprUse != InAction)
    ParseError("Tilldelning är inte tillåtet här");
  else if (exprUse == InCorr && lhs->type != Expr::Attribute)
    ParseError("Bara attribut tillåts i vänsterledet i en tilldelning.");
  else if (exprUse == InAction && lhs->type != Expr::Attribute &&
	       !(lhs->type == Expr::Operation && lhs->c.op.Op() == '.'
	       && lhs->c.op.Right()->type == Expr::Attribute))
    ParseError("Bara attribut tillåts i vänsterledet i en tilldelning.");
  else if (!Compatible(lhs, rhs))
    ParseError("Olika typ i höger- och vänsterled i tilldelning.");
  return new Expr(ASSIGNSYM, lhs->semtype, lhs, rhs); 
}

static Expr *IfExpr(Expr *condition, Expr *trueExpr, Expr *elseExpr) {
  int fclass = 0;
  if (trueExpr->type == Expr::Operation && trueExpr->c.op.Op() == ' ' &&
      exprUse != InMark && exprUse != InCorr)
    ParseError("Uppradning av uttryck är inte tillåtet efter THEN");
  else if (elseExpr->type == Expr::Operation && elseExpr->c.op.Op() == ' ' &&
	   exprUse != InMark && exprUse != InCorr)
    ParseError("Uppradning av uttryck är inte tillåtet efter ELSE");
  else if (IsFeature(trueExpr->semtype) && IsFeature(elseExpr->semtype)) {
    if (trueExpr->GetFeatureClass() == 0) fclass = elseExpr->GetFeatureClass(); else
      if (elseExpr->GetFeatureClass() == 0) fclass = trueExpr->GetFeatureClass(); else
	if (trueExpr->GetFeatureClass() == elseExpr->GetFeatureClass()) fclass = trueExpr->GetFeatureClass(); else
	  ParseError("Uttrycken efter THEN och ELSE har olika särdragsklasser.");
  } else {
    enum semantictype type = CoerseTypes(trueExpr->semtype, elseExpr->semtype);
    if (type == SemanticError)
      ParseError("Uttrycken efter THEN och ELSE har olika typ.");
    else {
      Expr *p = new Expr(IFSYM, type, condition,
			 new Expr(ELSESYM, type, trueExpr, elseExpr));
      p->featureClass = fclass;
      return p; 
    }
  }
  return NULL;
}


/* Semantiska rutiner som bygger upp den intermediära strukturen: */

static bool Compatible(const Expr *a, const Expr *b) {
  if (!a || !b) return false;
  if (IsFeature(a->semtype) && IsFeature(b->semtype)) {
    if (a->GetFeatureClass() != b->GetFeatureClass() &&
	a->GetFeatureClass() && b->GetFeatureClass()) return false;
    else return true;
  }
  if ((IsNumber(a->semtype) && IsNumber(b->semtype)) ||
      a->semtype == b->semtype) return true;
  else return false;
}
				 
char *value::ToString(enum semantictype semtype) const {
  char buf[100], *s;
  buf[0] = '\0';
  switch (semtype) {
  case Boolean:	sprintf(buf, "%s", boolean == 0 ? "false" : "true"); break;
  case Integer:	sprintf(buf, "%d", integer); break;
  case Real:	sprintf(buf, "%f", real); break;
  case String:	sprintf(buf, "%s", string); break;
  case Regexp:	sprintf(buf, "%s", regexp.regexp); break;
  case Variable:	sprintf(buf, "%s", evalVar.RealString()); break;
  case LexVariable:	sprintf(buf, "lex-variabel"); break;
  case Interval:	sprintf(buf, "intervall"); break;
  case SemFeatureClass:
  case Feature:	sprintf(buf, "%s", scrutinizer->Tags().GetFeature(feature).Name()); break;
  default: sprintf(buf, "okänd semantisk typ");
  }
// jbfix: purify claims memory leak
#if 0
  s = new char[strlen(buf) + 1];
#else
  s = infoStringBuf.NewString(strlen(buf) + 1);	
#endif
  strcpy(s, buf);
  return s;
}

void value::Print(enum semantictype semtype) const {
  switch (semtype) {
  case Boolean:	printf("%s", boolean == 0 ? "false" : "true"); break;
  case Integer:	printf("%d", integer); break;
  case Real:	printf("%f", real); break;
  case String:	printf("\"%s\"", string); break;
  case Regexp:	printf("\'%s\'", regexp.regexp); break;
  case Variable:	id->Print(); break;
  case LexVariable:	printf("lex-variabel"); break;
  case Interval:	printf("intervall"); break;
  case Feature:	printf("%s", scrutinizer->Tags().GetFeature(feature).Name()); break;
  case SemFeatureClass:	printf("särdragsklass (borde inte uppkomma)"); break;
  default: printf("okänd semantisk typ");
  }
}

Element *IdEntry::Elt(Element *environment) const { // ElementId, element {
  if (environment == NULL) return NULL;
  int index;
  switch (type) {
    case ElementId: index = u.elementIndex; break;
    case RuleElementId: index = u.re.elementIndex; break;
    default: return NULL;
  }
  return &environment[index];
}

/* RulesOK checks help rules and checks that labels and help rules that are
   used also are defined */
bool IdEntry::RulesOK(void) {
  bool OK = ruleSet.FixRules();
  endlabel->u.ruleNo = ruleSet.NRules();
  const IdEntry *s;
  for (int i=0; (s = (*globalsTable)[&i]); i++)
    if (s->type == LabelId && s->u.ruleNo < 0) {
      ParseErrorArg("Läget %s definieras aldrig", s->name);
      OK = false;
    }
  return OK;
}

/* Felmeddelandeutskrift, förhindrar kodgenerering: */
void ParseErrorArg(const char *s, const char *arg) {
  ParseWarningArg(s, arg);
  noCodeGeneration = 1;
}

void ParseError(const char *s) {
  ParseErrorArg(s, NULL);
}

/* Varningsmeddelandeutskrift, förhindrar inte kodgenerering: */
void ParseWarningArg(const char *s, const char *arg) {
  char buf[10000];
  sprintf(buf, s, arg);
  if (errorLine) {
    Message(MSG_WARNING, "row", int2str(errorLine), errorLineBuf);
    errorLine = 0;
  } else
    Message(MSG_WARNING, "row", int2str(line), ":", linebuf);
  Message(MSG_CONTINUE, buf);
}

static int yyerror(char*) {
  errorLine = line;
  strcpy(errorLineBuf, linebuf);
  return 0;
}

/* ParametersOK checks whether the number and types of parameters are
correct. If the parameters match 1 is returned, otherwise 0 is returned */
int MethodOrFunctionEntry::ParametersOK(Expr *actuals) const {
  int i;
  char buf[MAXLINELENGTH];
  if (noofargs == variablenoofargs) return 1;
  for (i = 0; i < noofargs && actuals;
	i++, actuals = actuals->c.op.Right()) {
    if (argtypes[i] != AnyType && 
	actuals->c.op.Left()->semtype != argtypes[i]) {
      sprintf(buf, "Fel på parameter %d i anropet av %s", i+1, Name());
      ParseError(buf);
      return 0;
    }
  }
  if (i != noofargs) {
    sprintf(buf, "För få parametrar (%d istället för %d) i anropet av %s", i, noofargs, Name());
    ParseError(buf);
    return 0;
  }
  if (actuals) {
    ParseErrorArg("För många parametrar i anropet av %s", Name());
    return 0;
  }
  return 1;
}

Expr *CreateConstant(const char *name, enum semantictype semtype) {
  IdEntry *p = IdEntry::LookUp(name);
  if (p->type != IdEntry::UndefinedId) return NULL;
  p->IntoGlobalTable(IdEntry::ConstantId);
  p->semtype = semtype;
  p->u.expr = new Expr(Expr::Leaf, semtype);
  return p->u.expr;
}

Expr *CreateFeature(const char *name, int fclass, int value) { 
  Expr *p = CreateConstant(name, Feature);
  if (!p)
    Message(MSG_ERROR, name, "is undefined");
  p->featureClass = fclass;
  p->c.feature = value;
  return p;
}

IdEntry *CreateFeatureClass(const char *name, int fclass) {
  IdEntry *id = new IdEntry(name, IdEntry::AttributeId, SemFeatureClass);
  id->u.featureClass = fclass;
  return id;
}

GotoEntry::GotoEntry(IdEntry *id_, Expr *nooftokens_) :
     id(id_), nooftokens(nooftokens_) {
}

void GotoEntry::Print() const {
  std::cout << "(" << id << "," << nooftokens << ")";
}

MethodOrFunctionEntry::MethodOrFunctionEntry(char *name_, enum idtype type_,
			  enum semantictype semtype_, int noofargs_)
  : IdEntry(name_), argtypes(0)
{
  type = type_;
  semtype = semtype_;
  noofargs = noofargs_;
  if (noofargs_ == variablenoofargs)
    argtypes = NULL;
  else {
    if (noofargs == 0)
      argtypes = NULL;
    else if (noofargs_ < 1 || noofargs > 100)
      Message(MSG_ERROR, Name(), "has ", int2str(noofargs), "arguments");
    else
      argtypes = new semantictype[noofargs];
  }
  featureClass = 0;
  IntoGlobalTable(type_);
}

MethodOrFunctionEntry::~MethodOrFunctionEntry()
{
    delete [] argtypes;
}

#include "eval.cpp"

static void colorfunc(MethodOrFunctionEntry*, EvaluatedVariable *p, const char *t,
		      const Expr*, union value[], union value &res) {
  if (p != NULL)
    t = p->GetWordToken()->LexString();
  res.string = t;
}

static void subfunc(MethodOrFunctionEntry*, EvaluatedVariable *p, const char *t, const Expr*,
		    union value argval[], union value &res) {
  //  cout << "subfunc called" << endl;
  int startpos = argval[0].integer;
  int len = argval[1].integer, tlen;
  if (p != NULL) t = p->GetWordToken()->LexString(); // GetWord()-> ?? johan
  tlen = strlen(t);
  if (startpos >= tlen) len = 0; else
  if (startpos + len > tlen) len = tlen - startpos;
  if (len > 0) {
    char *s = evalStringBuf.NewString(len+1); //new char[len + 1];
    strncpy(s, t + startpos, len);
    s[len] = '\0';
    res.string = s;
  } else
    res.string = "";
}

static bool AddForms(CorrThing *ct, WordTag *wt, ChangeableTag &tag) {
  const Tag *tag2;
  bool tagFound = false;
  for (int n=-1; (tag2 = tag.FindMatchingTag(n));) {
    tagFound = true;
    for (int j=0; j<wt->NLemmas(); j++)
      for (int k=0; k<wt->Lemma(j)->NInflectRules(); k++) {
	const WordTag *wt2 = wt->GetForm(tag2, j, k);
	if (wt2)
	  ct->Add(wt2->GetWord(), wt2->String());
      }
  }
  return tagFound;
}
/*
static void formFunc(MethodOrFunctionEntry*, EvaluatedVariable *p, const char *t,
		     const Expr *args, union value argval[], union value &res) {
    res.corrThing = NULL;
    for (int i=0; i<p->NMatchedWordTokens(); i++) {
	WordTag *wt;
	if (p == NULL) {
	    wt = scrutinizer->FindMainOrNewWord(t);
	    ensure(wt);
	} else
	    wt = p->GetWordToken(i)->GetWordTag();
	//    cout << p->GetWordToken(i) << endl;
	WordToken *tok = p->GetWordToken(i);
	CorrThing *ct = new CorrThing(CORR_REPLACE, tok); // new OK
	if (res.corrThing)
	    ct->SetNext(res.corrThing);
	res.corrThing = ct;
	ChangeableTag tag(*tok->SelectedTag()); // hur gör vi när p==NULL undrar Viggo
	int i = 0;
	for (const Expr *argp = args; argp; argp = argp->c.op.Right(), i++) {
	    const Expr *arg = argp->c.op.Left();
	    if (arg->type != Expr::Operation || arg->c.op.Op() != ASSIGNSYM) {
		Message(MSG_WARNING, "a parameter to form() is not an assignment");
	    } else {
		const Expr *attr = arg->c.op.Left();
		if (attr->semtype == String && attr->c.id == constantLemma) {
		    ensure(0);
		    //	wt = scrutinizer->FindMainOrNewWord(argval[i].string);
		    for (int j=0; j<wt->NLemmas(); j++) {
			Word *wt2 = wt->Lemma(j)->GetWord();
			ct->Add(wt2, wt2->String());
		    }
		    return;	  
		} else if (attr->semtype == SemFeatureClass) {
		    const int fClass = attr->GetFeatureClass();
		    const int fValue = argval[i].feature;
		    tag.SetFeature(fClass, fValue);
		} else
		    Message(MSG_WARNING, "non-feature assigned in form()");
	    }
	}
	bool tagFound = AddForms(ct, wt, tag);
	if (!tagFound) {
	    Message(MSG_WARNING, "form() cannot find the wanted tag",
		tag.String());
	    continue;
	} else if (ct->NStrings() == 0) // test using other word-tags of same word:
	    for (WordTag *wt2 = wt->GetWord(); wt2; wt2 = wt2->Next())
		if (wt2 != wt)
		    AddForms(ct, wt2, tag);
		if (ct->NStrings() == 0) {
		    Message(MSG_MINOR_WARNING, "form() cannot find the", tag.String(), "form of");
		    Message(MSG_CONTINUE, wt->String(), wt->GetTag()->String(),
			int2str(wt->GetWord()->InflectRule(0)));
		}
    }
}*/

static void formFunc(MethodOrFunctionEntry*, EvaluatedVariable *p, const char *t,
              const Expr *args, union value argval[], union value &res) {
     res.corrThing = NULL;
     for (int i=0; i<p->NMatchedWordTokens(); i++) {
     WordTag *wt;
     if (p == NULL) {
         wt = scrutinizer->FindMainOrNewWord(t);
         ensure(wt);
     } else
         wt = p->GetWordToken(i)->GetWordTag();
     //    cout << p->GetWordToken(i) << endl;
     WordToken *tok = p->GetWordToken(i);
     CorrThing *ct = new CorrThing(CORR_REPLACE, tok); // new OK
     if (res.corrThing)
         ct->SetNext(res.corrThing);
     res.corrThing = ct;
     ChangeableTag tag(*tok->SelectedTag()); // hur gÃ¶r vi nÃ¤r p==NULL undrar Viggo
     int k = 0;
     for (const Expr *argp = args; argp; argp = argp->c.op.Right(), k++) {
         const Expr *arg = argp->c.op.Left();
         if (arg->type != Expr::Operation || arg->c.op.Op() != ASSIGNSYM) {
         Message(MSG_WARNING, "a parameter to form() is not an assignment");
         } else {
         const Expr *attr = arg->c.op.Left();
         if (attr->semtype == String && attr->c.id == constantLemma) {
             ensure(0);
             //  wt = scrutinizer->FindMainOrNewWord(argval[k].string);
             for (int j=0; j<wt->NLemmas(); j++) {
             Word *wt2 = wt->Lemma(j)->GetWord();
             ct->Add(wt2, wt2->String());
             }
             return;
         } else if (attr->semtype == SemFeatureClass) {
             const int fClass = attr->GetFeatureClass();
             const int fValue = argval[k].feature;
             tag.SetFeature(fClass, fValue);
         } else
             Message(MSG_WARNING, "non-feature assigned in form()");
         }
     }
     bool tagFound = AddForms(ct, wt, tag);
     if (!tagFound) {
         Message(MSG_WARNING, "form() cannot find the wanted tag",
         tag.String());
         continue;
     } else if (ct->NStrings() == 0) // test using other word-tags of same word:
         for (WordTag *wt2 = wt->GetWord(); wt2; wt2 = wt2->Next())
         if (wt2 != wt)
             AddForms(ct, wt2, tag);
         if (ct->NStrings() == 0) {
             Message(MSG_MINOR_WARNING, "form() cannot find the", tag.String(), "form of");
             Message(MSG_CONTINUE, wt->String(), wt->GetTag()->String(),
             int2str(wt->GetWord()->InflectRule(0)));
         }
     }
}

static void concatfunc(MethodOrFunctionEntry*, const Expr*,
		       union value argval[], union value &res) {
  char *s = infoStringBuf.NewString(strlen(argval[0].string) + strlen(argval[1].string) + 1);
  sprintf(s, "%s%s", argval[0].string, argval[1].string);
  res.string = s;
}

static void smart_concatfunc(MethodOrFunctionEntry*, const Expr*,
		       union value argval[], union value &res) {
  // concatenates "jobb beskrivning" to "jobbeskrivning"
  const int len0 = strlen(argval[0].string);
  char *s = infoStringBuf.NewString(len0 + strlen(argval[1].string) + 1);
  if (len0 > 1 && IsConsonant(argval[1].string[0]) &&
      argval[0].string[len0-1] == argval[1].string[0] &&
      argval[0].string[len0-1] == argval[0].string[len0-2])
    sprintf(s, "%s%s", argval[0].string, argval[1].string+1);
  else
    sprintf(s, "%s%s", argval[0].string, argval[1].string);
  //  cout << argval[0].string << " + " <<  argval[1].string << " = " << s << endl;
  res.string = s;
}

static void tolowerfunc(MethodOrFunctionEntry*, const Expr*,
			union value argval[], union value &res) {
  char *s = infoStringBuf.NewString(argval[0].string);
  ToLower(s);
  res.string = s;
}

static void toupperfunc(MethodOrFunctionEntry*, const Expr*,
			union value argval[], union value &res) {
  char *s = infoStringBuf.NewString(argval[0].string);
  ToUpper(s);
  res.string = s;
}

static void firsttoupperfunc(MethodOrFunctionEntry*, const Expr*,
			     union value argval[], union value &res) {
  char *s = infoStringBuf.NewString(argval[0].string);
  *s = Upper(*s);
  res.string = s;
}

static void italicfunc(MethodOrFunctionEntry *, const Expr*,
		       union value argval[], union value &res) {
  if (argval[0].string[0] == '\0')
    res.string = "";
  else {
    char *s = infoStringBuf.NewString(strlen(argval[0].string) + strlen(xItalic) + 
				      strlen(xNoItalic) + 1);
    sprintf(s, "%s%s%s", xItalic, argval[0].string, xNoItalic);
    res.string = s;
  }
}

static void boldfunc(MethodOrFunctionEntry *, const Expr*,
		     union value argval[], union value &res) {
  char *s = infoStringBuf.NewString(strlen(argval[0].string) + 8);
  sprintf(s, "<B>%s</B>", argval[0].string);
  res.string = s;
}

static void tostringfunc(MethodOrFunctionEntry*, const Expr* args,
			 union value argval[], union value &res) {
  res.string = argval[0].ToString(args->c.op.Left()->semtype);
}

static void strangesentencefunc(MethodOrFunctionEntry*, const Expr *args,
				union value [], union value &res) { 
  const AbstractSentence *s = args->CurrentMatching()->GetSentence();
  res.boolean = s->SeemsForeign();
}

static void containsrepeatedwordsfunc(MethodOrFunctionEntry*, const Expr *args,
				union value [], union value &res) { 
  const AbstractSentence *s = args->CurrentMatching()->GetSentence();
  res.boolean = s->ContainsRepeatedWords();
}

static void containsStyleWordFunc(MethodOrFunctionEntry*, const Expr *args,
				union value [], union value &res) { 
  const AbstractSentence *s = args->CurrentMatching()->GetSentence();
  res.boolean = s->ContainsStyleWord();
}

static void CollectSpellSuggestions(CorrThing *ct, char *corr) {
  if (!corr) return;
  int n = 0;
  for (const char *s = strtok(corr, "\t"); s; s = strtok(NULL, "\t")) {
    ct->Add(NULL, s);
    if (++n >= xMaxSpellSuggestions)
      break;
  }
}

static void correctlyspelledfunc(MethodOrFunctionEntry*, const Expr*,
				 union value argval[], union value &res) {
  res.boolean = scrutinizer->IsSpellOK(argval[0].string, (Token)argval[1].integer);
  return;
}

static void spellCorrectFunc(MethodOrFunctionEntry*, EvaluatedVariable *ev, const char*, 
			     const Expr*, union value argval[], union value &res) {
  char *corr = scrutinizer->SpellOK(argval[0].string, (Token)argval[1].integer);
  res.corrThing = new CorrThing(CORR_REPLACE, ev->GetWordToken()); // new OK
  CollectSpellSuggestions(res.corrThing, corr);
  return;
}

static void spellcompoundcheckfunc(MethodOrFunctionEntry*, EvaluatedVariable*, const char*, 
				   const Expr*, union value argval[], union value &res) {
  //  if (xVerbose)
  //    cout << xCurrentRule << " compound: '" << argval[0].string << "'" << endl;
  /*
  const char *string = NULL;
  if (argval[1].integer == TOKEN_SPLIT_WORD) {
    for (int p = strlen(argval[0].string)-2; p>0; p--)
      if (IsSpace(argval[0].string[p])) {
	string = argval[0].string+p+1;
	break;
      }
    ensure(string);
  } else if (argval[1].integer == TOKEN_ABBREVIATION) {
    res.boolean = true;
    return;
  } else
    string = argval[0].string;
  */
  if (argval[1].integer == TOKEN_SIMPLE_WORD)
    res.boolean = (StavaCorrectCompound((unsigned char *) argval[0].string)) ? true : false;
  else
    res.boolean = true;
}

static void spellCorrectCompoundFunc(MethodOrFunctionEntry*, EvaluatedVariable *ev, const char*, 
				     const Expr*, union value argval[], union value &res) {
  char *corr = NULL;
  if (argval[1].integer == TOKEN_SPLIT_WORD) {
    for (int p = strlen(argval[0].string)-2; p>0; p--)
      if (IsSpace(argval[0].string[p])) {
	corr = (char *) StavaCorrectCompound((unsigned char *) argval[0].string+p+1);
	break;
      }
  } else
    corr = (char *) StavaCorrectCompound((unsigned char *) argval[0].string);
  res.corrThing = new CorrThing(CORR_REPLACE, ev->GetWordToken()); // new OK
  CollectSpellSuggestions(res.corrThing, corr);
}

static void spellinfofunc(MethodOrFunctionEntry*, EvaluatedVariable*, const char*, 
			  const Expr*, union value argval[], union value &res) {
  switch ((Token)argval[0].integer) {
  case TOKEN_SPLIT_WORD:
    res.string = "Okänt ord bland uppdelade ord"; break;
  case TOKEN_TIME:
    res.string = "Okonventionellt eller felaktigt skrivsätt av klockslag"; break;
  case TOKEN_DATE:
    res.string = "Okonventionellt eller felaktigt skrivsätt av datum"; break;
  case TOKEN_YEAR:
    res.string = "Okonventionellt eller felaktigt skrivsätt av årtal (nyrad?)"; break;
  case TOKEN_PARAGRAPH:
    res.string = "Okonventionellt eller felaktigt skrivsätt av paragraf"; break;
  case TOKEN_BAD_CARDINAL:
    res.string = "Okonventionellt eller felaktigt skrivsätt av tal"; break;
  case TOKEN_PERCENTAGE:
    res.string = "Okonventionellt eller felaktigt skrivsätt av procentuttryck"; break;
  case TOKEN_ABBREVIATION:
    res.string = "Okänd förkortning eller förkortning av oförkortat ord i texten"; break;
  default:
    res.string = "Okänt ord";
  }
}

static void joinFunc(MethodOrFunctionEntry*, EvaluatedVariable *ev, const char*, 
		     const Expr*, union value argval[], union value &res) {
  res.corrThing = new CorrThing(CORR_JOIN, ev->GetWordToken()); // new OK
  res.corrThing->Add(NULL, argval[0].string);
}

static void replaceFunc(MethodOrFunctionEntry*, EvaluatedVariable *ev, const char*, 
			const Expr*, union value argval[], union value &res) {
  res.corrThing = new CorrThing(CORR_REPLACE, ev->GetWordToken()); // new OK
  res.corrThing->Add(NULL, argval[0].string);
}

static void insertFunc(MethodOrFunctionEntry*, EvaluatedVariable *ev, const char*, 
		       const Expr*, union value argval[], union value &res) {
  res.corrThing = new CorrThing(CORR_INSERT, ev->GetWordToken()); // new OK
  res.corrThing->Add(NULL, argval[0].string);
}

static void deleteFunc(MethodOrFunctionEntry*, EvaluatedVariable *ev, const char*, 
		       const Expr*, union value argval[], union value &res) {
  res.corrThing = new CorrThing(CORR_DELETE, ev->GetWordToken()); // new OK
}

static void doNothingFunc(MethodOrFunctionEntry*, EvaluatedVariable *ev, const char*, 
			  const Expr*, union value argval[], union value &res) {
  res.corrThing = new CorrThing(CORR_DO_NOTHING, ev->GetWordToken()); // new OK
}


static void token_start(MethodOrFunctionEntry     *me,
                        EvaluatedVariable         *ev,
                        const                      char*,
                        const Expr                *args,
                        union value                argval[],
                        union value               &res)
{
    res.integer = 0;
}


#ifdef PROBCHECK
// jb: added the probabilistic checker 2001-04-23
#include "prob.h"
static void prob_check(MethodOrFunctionEntry    *,
                       EvaluatedVariable        *ev,
                       const                     char*,
                       const Expr               *args,
                       union value               argval[],
                       union value              &res)
{
#if 1
    res.integer =
    Prob::prob_check(scrutinizer, args->CurrentMatching()->GetSentence());
#else
    static int count = 0;
    res.integer = count++;
#endif

}

static void last_prob_err(MethodOrFunctionEntry     *w,
                          const Expr                *args,
                          union value                argval[],
                          union value               &res)
{
    res.integer = Prob::last_prob_error();
}

#endif // PROBCHECK


#ifdef TRANSITIVITY
// jb: added transitivity 2001-06-18
#include "trans.h"
static void intrans(MethodOrFunctionEntry     *w,
                    const Expr                *args,
                    union value                argval[],
                    union value               &res)
{
    res.boolean =
	(Trans::lookup(argval[0].string) & Trans::T_INTRANS) != 0;
}

static void trans(MethodOrFunctionEntry     *w,
                  const Expr                *args,
                  union value                argval[],
                  union value               &res)
{
    res.boolean =
	(Trans::lookup(argval[0].string) & Trans::T_TRANS) != 0;
}

static void bitrans(MethodOrFunctionEntry     *w,
                    const Expr                *args,
                    union value                argval[],
                    union value               &res)
{
    res.boolean =
	(Trans::lookup(argval[0].string) & Trans::T_BITRANS) != 0;
}

static void refl_intrans(MethodOrFunctionEntry     *w,
                         const Expr                *args,
                         union value                argval[],
                         union value               &res)
{
    res.boolean =
	(Trans::lookup(argval[0].string) & Trans::T_REFL_INTRANS) != 0;
}

static void refl_trans(MethodOrFunctionEntry     *w,
                       const Expr                *args,
                       union value                argval[],
                       union value               &res)
{
    res.boolean =
	(Trans::lookup(argval[0].string) & Trans::T_REFL_TRANS) != 0;
}

static void refl_bitrans(MethodOrFunctionEntry     *w,
                         const Expr                *args,
                         union value                argval[],
                         union value               &res)
{
    res.boolean =
	(Trans::lookup(argval[0].string) & Trans::T_REFL_BITRANS) != 0;
}

#endif // TRANSITIVITY



static int CompareEntries(const IdEntry &e1, const IdEntry &e2) {
  return strcmp(e1.Name(), e2.Name());
}
static uint KeyIdEntry(const IdEntry &e) {
  return Hash(e.Name());
}

static void InitTables(void) {
  InitSemantics();
  IdEntry::globalsTable = new HashTable<IdEntry>(KeyIdEntry, CompareEntries, NULL, NULL);
}

void DefinePredefined(void) {
  MethodOrFunctionEntry *pm;
  if (1 == 2) yyunput(0, NULL); /* just to avoid warning of unused function */
  endlabel = IdEntry::LookUp("endlabel");
  endlabel->IntoGlobalTable(IdEntry::LabelId);
  endlabel->u.ruleNo = MAX_RULES;
  IdEntry *beginlabel = IdEntry::LookUp("beginlabel");
  beginlabel->IntoGlobalTable(IdEntry::LabelId);
  beginlabel->u.ruleNo = 0;
  constantAlmostOne = CreateConstant("0.9999", Real); 
  constantAlmostOne->c.real = 0.9999;
  constantAlmostZero = CreateConstant("0.0001", Real); 
  constantAlmostZero->c.real = 0.0001;
  constantFalse = CreateConstant("false", Boolean);
  constantFalse->c.boolean = false;
  constantTrue = CreateConstant("true", Boolean);
  constantTrue->c.boolean = true;
  CreateConstant("red", Integer)->c.integer = 1;
  CreateConstant("blue", Integer)->c.integer = 2;
  CreateConstant("green", Integer)->c.integer = 3;
  CreateConstant("yellow", Integer)->c.integer = 4;
  //  CreateFeature("undef", 0, FEATURE_UNDEF);
  for (int i = 0; i < scrutinizer->Tags().NFeatureClasses(); i++) {
    const FeatureClass &fc = scrutinizer->Tags().GetFeatureClass(i);
    // printf("Ny särdragsklass %d: %s\n", i, fc.Name());
    CreateFeatureClass(fc.Name(), i);
    for (int j = 0; j < fc.NFeatures(); j++) {
      int f = fc.GetFeature(j);
      // printf("Nytt särdrag %d \n", f);
      // printf("med namnet %s\n", scrutinizer->Tags().GetFeature(f).Name());
      CreateFeature(scrutinizer->Tags().GetFeature(f).Name(), i, f);
    }
  }
  for (int k=0; k < N_TOKENS; k++)
    CreateConstant(Token2String((Token)k), Integer)->c.integer = k;
  constantSpellOK = new IdEntry("spellOK", IdEntry::AttributeId, Boolean);
  constantBeginOK = new IdEntry("beginOK", IdEntry::AttributeId, Boolean);
  constantEndOK = new IdEntry("endOK", IdEntry::AttributeId, Boolean);
  constantIsRepeated = new IdEntry("is_repeated", IdEntry::AttributeId, Boolean);
  constantToken = new IdEntry("token", IdEntry::AttributeId, Integer);
  constantText = new IdEntry("text", IdEntry::AttributeId, String);
  constantRealText = new IdEntry("real_text", IdEntry::AttributeId, String);
  constantVerbtype = new IdEntry("verbtype", IdEntry::AttributeId, Integer);
  constantLemma = new IdEntry("lemma", IdEntry::AttributeId, String);
  constantNoOfTokens = new IdEntry("no_of_tokens", IdEntry::AttributeId, Integer);
  constantLength = new IdEntry("length", IdEntry::AttributeId, Integer);
  constantGetReplacement = new IdEntry("get_replacement", IdEntry::AttributeId, String);
  constantGetValues = new IdEntry("get_values", IdEntry::AttributeId, Boolean);
  constantLex = new IdEntry("lex", IdEntry::AttributeId, LexVariable);
  constantCap = new IdEntry("is_cap", IdEntry::AttributeId, Boolean);
  constantAllCap = new IdEntry("is_all_cap", IdEntry::AttributeId, Boolean);
  constantIsForeign = new IdEntry("is_foreign", IdEntry::AttributeId, Boolean);
  pm = new MethodOrFunctionEntry("substr", IdEntry::MethodId, String, 2);
  pm->func.method = &subfunc;
  pm->argtypes[0] = pm->argtypes[1] = Integer;
  pm = new MethodOrFunctionEntry("color", IdEntry::MethodId, String, 1);
  pm->func.method = &colorfunc;
  pm->argtypes[0] = Integer;
  pm = new MethodOrFunctionEntry("form", IdEntry::MethodId, 
       CorrT, MethodOrFunctionEntry::variablenoofargs);
  pm->func.method = &formFunc;
  pm = new MethodOrFunctionEntry("concat", IdEntry::FunctionId, String, 2);
  pm->func.function = &concatfunc;
  pm->argtypes[0] = pm->argtypes[1] = String;
  pm = new MethodOrFunctionEntry("smart_concat", IdEntry::FunctionId, String, 2);
  pm->func.function = &smart_concatfunc;
  pm->argtypes[0] = pm->argtypes[1] = String;
  pm = new MethodOrFunctionEntry("tolower", IdEntry::FunctionId, String, 1);
  pm->func.function = &tolowerfunc;
  pm->argtypes[0] = String;
  pm = new MethodOrFunctionEntry("toupper", IdEntry::FunctionId, String, 1);
  pm->func.function = &toupperfunc;
  pm->argtypes[0] = String;
  pm = new MethodOrFunctionEntry("firsttoupper", IdEntry::FunctionId, String, 1);
  pm->func.function = &firsttoupperfunc;
  pm->argtypes[0] = String;
  pm = new MethodOrFunctionEntry("italics", IdEntry::FunctionId, String, 1);
  pm->func.function = &italicfunc;
  pm->argtypes[0] = String;
  pm = new MethodOrFunctionEntry("bold", IdEntry::FunctionId, String, 1);
  pm->func.function = &boldfunc;
  pm->argtypes[0] = String;
  pm = new MethodOrFunctionEntry("tostring", IdEntry::FunctionId, String, 1);
  pm->func.function = &tostringfunc;
  pm->argtypes[0] = AnyType;
  pm = new MethodOrFunctionEntry("spell_OK", IdEntry::FunctionId, Boolean, 2);
  pm->func.function = &correctlyspelledfunc;
  pm->argtypes[0] = String;
  pm->argtypes[1] = Integer;
  pm = new MethodOrFunctionEntry("spell_corr", IdEntry::MethodId, CorrT, 2);
  pm->func.method = &spellCorrectFunc;
  pm->argtypes[0] = String;
  pm->argtypes[1] = Integer;
  pm = new MethodOrFunctionEntry("spell_corr_compound", IdEntry::MethodId, CorrT, 2);
  pm->func.method = &spellCorrectCompoundFunc;
  pm->argtypes[0] = String;
  pm->argtypes[1] = Integer;
  pm = new MethodOrFunctionEntry("spell_compound_OK", IdEntry::MethodId, Boolean, 2);
  pm->func.method = &spellcompoundcheckfunc;
  pm->argtypes[0] = String;
  pm->argtypes[1] = Integer;
  pm = new MethodOrFunctionEntry("spell_info", IdEntry::MethodId, String, 1);
  pm->func.method = &spellinfofunc;
  pm->argtypes[0] = Integer;
  pm = new MethodOrFunctionEntry("strange_sentence", IdEntry::FunctionId, Boolean, 0);
  pm->func.function = &strangesentencefunc;
  pm = new MethodOrFunctionEntry("contains_repeated_words", IdEntry::FunctionId, Boolean, 0);
  pm->func.function = &containsrepeatedwordsfunc;
  pm = new MethodOrFunctionEntry("contains_style_word", IdEntry::FunctionId, Boolean, 0);
  pm->func.function = &containsStyleWordFunc;
  pm = new MethodOrFunctionEntry("join", IdEntry::MethodId, CorrT, 1);
  pm->func.method = &joinFunc;
  pm->argtypes[0] = String;
  pm = new MethodOrFunctionEntry("replace", IdEntry::MethodId, CorrT, 1);
  pm->func.method = &replaceFunc;
  pm->argtypes[0] = String;
  pm = new MethodOrFunctionEntry("insert", IdEntry::MethodId, CorrT, 1);
  pm->func.method = &insertFunc;
  pm->argtypes[0] = String;
  pm = new MethodOrFunctionEntry("delete", IdEntry::MethodId, CorrT, 0);
  pm->func.method = &deleteFunc;
  pm = new MethodOrFunctionEntry("donothing", IdEntry::MethodId, CorrT, 0);
  pm->func.method = &doNothingFunc;



  pm = new MethodOrFunctionEntry("token_start", IdEntry::MethodId, Integer, 0);
  pm->func.method = &token_start;

#ifdef PROBCHECK
  pm = new MethodOrFunctionEntry("probcheck", IdEntry::MethodId, Integer, 0);
  pm->func.method = &prob_check;
  pm = new MethodOrFunctionEntry("lastproberr", IdEntry::FunctionId, Integer, 0);
  pm->func.function = &last_prob_err;
#endif // PROBCHECK

#ifdef TRANSITIVITY
  pm = new MethodOrFunctionEntry("intrans", IdEntry::FunctionId, Boolean, 1);
  pm->func.function = &intrans;
  pm->argtypes[0] = String;
  pm = new MethodOrFunctionEntry("trans", IdEntry::FunctionId, Boolean, 1);
  pm->func.function = &trans;
  pm->argtypes[0] = String;
  pm = new MethodOrFunctionEntry("bitrans", IdEntry::FunctionId, Boolean, 1);
  pm->func.function = &bitrans;
  pm->argtypes[0] = String;
  pm = new MethodOrFunctionEntry("intrans_refl", IdEntry::FunctionId, Boolean, 1);
  pm->func.function = &refl_intrans;
  pm->argtypes[0] = String;
  pm = new MethodOrFunctionEntry("trans_refl", IdEntry::FunctionId, Boolean, 1);
  pm->func.function = &refl_trans;
  pm->argtypes[0] = String;
  pm = new MethodOrFunctionEntry("bitrans_refl", IdEntry::FunctionId, Boolean, 1);
  pm->func.function = &refl_bitrans;
  pm->argtypes[0] = String;
#endif // TRANSITIVITY
}

/* Memory handling */

static Element *Ebuf = NULL;
static int EfirstUnused = 0;

Element *NewElements(Element *p, int n) {
  if (n == 0) return NULL;
  if (Ebuf == NULL || EfirstUnused + n > NEW_ELEMENTS_BUF_SIZE) {
    Message(MSG_STATUS, "allocating Elements...");
    if (Ebuf)
      Message(MSG_WARNING, "allocating Elements, increase NEW_ELEMENTS_BUF_SIZE");
    int size = (n > NEW_ELEMENTS_BUF_SIZE) ? n : NEW_ELEMENTS_BUF_SIZE;
    Ebuf = new Element[size];
    if (!Ebuf) return NULL; // No memory left!
    EfirstUnused = 0;
  }
  Element *start = Ebuf + EfirstUnused;
  memcpy(start, p, n * sizeof(Element));
  EfirstUnused += n;
  return start;
}

void DeleteElements() {
  delete[] Ebuf;
  Ebuf = NULL;   // old Ebufs not deleted
}

RuleSet *ReadRules(Scrutinizer *s, const char *ruleFile) {
  if (!s->IsLoaded()) {
    Message(MSG_ERROR, "trying to load rules with unloaded scrutinizer");
    return NULL;
  }
  scrutinizer = s;
  InitTables();
  Message(MSG_STATUS, "rule tables initialized");
  DefinePredefined();
  Message(MSG_STATUS, "rules initialized");
  yyin = fopen(ruleFile, "r");
  if(!yyin)		// jbfix: non-existing file caused infinite loop
  {
    Message(MSG_ERROR, "rules file", ruleFile, "could not be found");
    return NULL;
  }
  yyparse();
  Message(MSG_STATUS, "loading", ruleFile, "...");
  if (errorLine)
    ParseError("Syntaxfel i regeldefinitionerna");
  if (!noCodeGeneration && !IdEntry::RulesOK())
    noCodeGeneration = 1;
  if (noCodeGeneration) {
    Message(MSG_ERROR, "no code generated");
    return NULL;
  }

  ruleSet.ComputeScope();
  Message(MSG_STATUS, "rules read");
  return &ruleSet;
}


