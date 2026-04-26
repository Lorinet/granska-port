###############################################
#
#  makefile -- fil för att bygga projektet
#
#  skriv först make depend för att bygga
#    beroenden (tillkommer nederst i makefilen)
#  skriv sedan make som vanligt
#
CPPC = g++ # c++-kompilator
CC   = gcc # c-kompilator
WARN_PERFORMANCE = -Winline -Wpadded -Wdisabled-optimization
WARN_STRICT = -Wchar-subscripts -Wcomment -Wimplicit -Wparentheses -Wsequence-point -Wreturn-type -Wswitch -Wuninitialized -Wreorder -Wno-system-headers -Wpointer-arith -Wno-cast-qual -Wcast-align -Wwrite-strings -Wno-missing-declarations -Wunreachable-code 
WARN =  -Wall -Wno-missing-braces -Wno-unknown-pragmas -Wno-unused-function -Wno-unused-label #warning do not use the -pedantic flag, since it reports error for standalone semicolons.
DEBUG_FLAGS = -g -DENSURE
RELEASE_FLAGS = -O3 #$(WARN_PERFORMANCE)

#CFLAGS = $(RELEASE_FLAGS) $(WARN)# gemensamma inställningar
CFLAGS = $(DEBUG_FLAGS) $(WARN)# gemensamma inställningar

#
#  Directories and paths
#
CD = common# common files directory
TD = tagger# tagger files directory
SD = scrut# scrutinizer files directory
PD = prob# probcheck files directory
STD = stava# stava files directory
TOD = token# tokenizer files directory
CGID = cgigranska# cgigranska files directory
#XERCES = /usr
#INCL = -I$(XERCES)/include/xercesc
FLAGS = $(CFLAGS) -I$(CD) -I$(TD) -I$(SD) -I$(PD) -I$(STD) \
  -I$(TOD) -I.. -DNO_XML_SUPPORT -DNO_ANNOT_FROM_FILE
#LIB_PATH = -L$(XERCES)/lib
#LIB_PATH_RT = -R$(XERCES)/lib #set runtime-path at compile time

STAVA_OBJ = $(STD)/stavaapi.o $(STD)/suffix.o $(STD)/rattstava.o
STAVA_FLAGS = -DAPI

TOK_OBJ = $(TOD)/tokenizer.o

MAIN_OBJ = $(CD)/main.o
COMMON_OBJ = $(CD)/file.o $(CD)/message.o $(CD)/timer.o
COMMON_FLAGS = 

WWW_OBJ = $(CGID)/wwwmain.o $(CGID)/wwwscrutinizer.o

TAGGER_OBJ = $(TD)/hashscatter.o $(TD)/inflectlexicon.o\
  $(TD)/inflectrule.o $(TD)/letter.o $(TD)/lexicon.o\
  $(TD)/morflexicon.o $(TD)/newwordlexicon.o $(TD)/sentence.o\
  $(TD)/settings.o $(TD)/tag.o $(TD)/tagger.o $(TD)/taglexicon.o\
  $(TD)/text.o $(TD)/word.o $(TD)/wordlexicon.o $(TD)/wordtag.o\
  $(TD)/wordtoken.o
TAGGER_FLAGS = -DPROB_DOUBLE # jonas, I get lots of prob = 0 (smaller than float limit) otherwise

# leave lex/yacc files first because of the files they generate
# and the dependencies that other files have
SCRUT_OBJ = $(SD)/rules.tab.o $(SD)/element.o $(SD)/expr.o\
  $(SD)/gramerror.o $(SD)/identry.o $(SD)/matching.o\
  $(SD)/matchingset.o $(SD)/operation.o $(SD)/rule.o $(SD)/ruleset.o\
  $(SD)/rulesettings.o $(SD)/scrutinizer.o
SCRUT_FLAGS = -DMESSAGES -DTIMER -DDEVELOPER_OUTPUT

PROBCHECK_OBJ = $(PD)/annot.o $(PD)/output.o\
  $(PD)/probcheck.o $(PD)/trans.o $(PD)/report.o $(PD)/probdevelop.o $(PD)/probinfo.o $(PD)/probmatch.o \
  $(PD)/represent.o $(PD)/probadmin.o \
  ../misc/xmloutput.o
PROBCHECK_FLAGS = -DPROBCHECK -DNO_SENTENCE_DELIMITERS  
  #-DTRANSITIVITY -DNO_XML_SUPPORT -DNO_ANNOT_FROM_FILE 

WEB_OBJ = $(SD)/web.o $(SD)/socket.o $(SD)/server_socket.o
WEB_FLAGS = -DWEB_SCRUTINIZER
WEB_LIBS = -lsocket -lnsl

ALLWWW_OBJ = $(WWW_OBJ) $(SCRUT_OBJ) $(COMMON_OBJ) $(STAVA_OBJ) $(TOK_OBJ) $(TAGGER_OBJ) $(PROBCHECK_OBJ)
ALL_OBJ = $(MAIN_OBJ) $(SCRUT_OBJ) $(COMMON_OBJ) $(STAVA_OBJ) $(TOK_OBJ)\
  $(TAGGER_OBJ) $(PROBCHECK_OBJ)

STATIC_FLAGS = -O3 -static -static-libgcc -static-libstdc++ -no-pie
ALL_FLAGS = $(FLAGS) $(COMMON_FLAGS) $(STAVA_FLAGS) $(TOK_FLAGS)\
  $(DEVELOPERS_TAGGER_FLAGS) $(TAGGER_FLAGS) $(SCRUT_FLAGS) $(PROBCHECK_FLAGS) $(STATIC_FLAGS)

TAGG_OBJ = $(CD)/file.o $(CD)/message.o $(CD)/timer.o $(TD)/main.o\
  $(TOK_OBJ) $(TAGGER_OBJ)

DTD = developers-tagger
DEVELOPERS_TAGGER_OBJ=$(DTD)/main.o $(DTD)/developers-tagger.o $(DTD)/settings_manip.o
# do not use DEVELOPERS_TAGGER_FLAGS unless building developers tagger (defines optConst, CheckHash)
DEVELOPERS_TAGGER_FLAGS=-DDEVELOPERS
DEVELOPERS_HELPER_OBJ=$(DEVELOPERS_TAGGER_OBJ) $(TOK_OBJ) $(TAGGER_OBJ) $(CD)/file.o $(CD)/message.o $(CD)/timer.o
DEVELOPERS_TAGG_OBJ = $(patsubst %.o, %.do, $(DEVELOPERS_HELPER_OBJ))

TARGETS = scrutinizer libgranska.a
LIBS = 
WWWLIBS = -lxerces-c1_6_0

all: $(TARGETS)

developers-tagg: $(DEVELOPERS_TAGG_OBJ)
	$(CPPC) $(FLAGS) -o $@ $^ $(LIBS) \

scrutinizer: $(ALL_OBJ)
	$(CPPC) $(ALL_FLAGS) -o scrutinizer $(ALL_OBJ) $(LIB_PATH) $(LIBS)

libgranska.a: $(SCRUT_OBJ) $(COMMON_OBJ) $(STAVA_OBJ) $(TOK_OBJ) $(TAGGER_OBJ)
	ar rcs libgranska.a $(SCRUT_OBJ) $(COMMON_OBJ) $(STAVA_OBJ) $(TOK_OBJ) $(TAGGER_OBJ)

wwwscrutinizer: $(ALLWWW_OBJ)
	$(CPPC) $(ALL_FLAGS) -Bstatic -o wwwscrutinizer $(ALLWWW_OBJ) $(WWWLIBS)
	strip wwwscrutinizer

tagg: $(TAGG_OBJ)
	$(CPPC) $(FLAGS) -o $@ $^ $(LIB_PATH) $(LIBS)

%.o: %.cpp
	$(CPPC) $(ALL_FLAGS) -Idevelopers-tagger -c $*.cpp -o $*.o

%.o: %.c
	$(CC) $(ALL_FLAGS) -fgnu89-inline -c $*.c -o $*.o

%.do: %.cpp
	$(CPPC) $(ALL_FLAGS) $(DEVELOPERS_TAGGER_FLAGS) -c $< -o $@

$(SD)/rules.tab.cpp: $(SD)/rules.y $(SD)/lex.yy.c
	cd $(SD) ; bison -v -d rules.y
	mv $(SD)/rules.tab.c $(SD)/rules.tab.cpp

$(SD)/rules.tab.h: $(SD)/rules.y $(SD)/lex.yy.c
	cd $(SD); bison -v -d rules.y

$(SD)/lex.yy.c: $(SD)/rules.l 
	flex -f -8 $(SD)/rules.l
	mv lex.yy.c $(SD)

clean: 
	rm -f *.o *~ */*.o */*~
	rm -f *.do */*.do 
	rm -f $(SD)/*.tab.c $(SD)/*.tab.cpp $(SD)/*.tab.h
	rm -f $(SD)/*.yy.c $(SD)/*.output
	rm -f ../misc/xmloutput.o
	rm -f core messages

realclean: clean 	
	rm -f $(TARGETS)
	rm -f tagg

depend:
	makedepend -- $(ALL_FLAGS) -- */*.cpp */*.c

# DO NOT DELETE

cgigranska/wwwmain.o: /usr/include/sys/types.h /usr/include/features.h
cgigranska/wwwmain.o: /usr/include/features-time64.h
cgigranska/wwwmain.o: /usr/include/bits/wordsize.h
cgigranska/wwwmain.o: /usr/include/bits/timesize.h /usr/include/stdc-predef.h
cgigranska/wwwmain.o: /usr/include/sys/cdefs.h
cgigranska/wwwmain.o: /usr/include/bits/long-double.h
cgigranska/wwwmain.o: /usr/include/gnu/stubs.h /usr/include/bits/types.h
cgigranska/wwwmain.o: /usr/include/bits/typesizes.h
cgigranska/wwwmain.o: /usr/include/bits/time64.h
cgigranska/wwwmain.o: /usr/include/bits/types/clock_t.h
cgigranska/wwwmain.o: /usr/include/bits/types/clockid_t.h
cgigranska/wwwmain.o: /usr/include/bits/types/time_t.h
cgigranska/wwwmain.o: /usr/include/bits/types/timer_t.h
cgigranska/wwwmain.o: /usr/include/bits/stdint-intn.h /usr/include/endian.h
cgigranska/wwwmain.o: /usr/include/bits/endian.h
cgigranska/wwwmain.o: /usr/include/bits/endianness.h
cgigranska/wwwmain.o: /usr/include/bits/byteswap.h
cgigranska/wwwmain.o: /usr/include/bits/uintn-identity.h
cgigranska/wwwmain.o: /usr/include/sys/select.h /usr/include/bits/select.h
cgigranska/wwwmain.o: /usr/include/bits/types/sigset_t.h
cgigranska/wwwmain.o: /usr/include/bits/types/__sigset_t.h
cgigranska/wwwmain.o: /usr/include/bits/types/struct_timeval.h
cgigranska/wwwmain.o: /usr/include/bits/types/struct_timespec.h
cgigranska/wwwmain.o: /usr/include/bits/pthreadtypes.h
cgigranska/wwwmain.o: /usr/include/bits/thread-shared-types.h
cgigranska/wwwmain.o: /usr/include/bits/pthreadtypes-arch.h
cgigranska/wwwmain.o: /usr/include/bits/atomic_wide_counter.h
cgigranska/wwwmain.o: /usr/include/bits/struct_mutex.h
cgigranska/wwwmain.o: /usr/include/bits/struct_rwlock.h
cgigranska/wwwmain.o: /usr/include/sys/wait.h /usr/include/signal.h
cgigranska/wwwmain.o: /usr/include/bits/signum-generic.h
cgigranska/wwwmain.o: /usr/include/bits/signum-arch.h
cgigranska/wwwmain.o: /usr/include/bits/types/sig_atomic_t.h
cgigranska/wwwmain.o: /usr/include/bits/types/siginfo_t.h
cgigranska/wwwmain.o: /usr/include/bits/types/__sigval_t.h
cgigranska/wwwmain.o: /usr/include/bits/siginfo-arch.h
cgigranska/wwwmain.o: /usr/include/bits/siginfo-consts.h
cgigranska/wwwmain.o: /usr/include/bits/types/sigval_t.h
cgigranska/wwwmain.o: /usr/include/bits/types/sigevent_t.h
cgigranska/wwwmain.o: /usr/include/bits/sigevent-consts.h
cgigranska/wwwmain.o: /usr/include/bits/sigaction.h
cgigranska/wwwmain.o: /usr/include/bits/sigcontext.h
cgigranska/wwwmain.o: /usr/include/bits/types/stack_t.h
cgigranska/wwwmain.o: /usr/include/sys/ucontext.h
cgigranska/wwwmain.o: /usr/include/bits/sigstack.h
cgigranska/wwwmain.o: /usr/include/bits/sigstksz.h
cgigranska/wwwmain.o: /usr/include/bits/ss_flags.h
cgigranska/wwwmain.o: /usr/include/bits/types/struct_sigstack.h
cgigranska/wwwmain.o: /usr/include/bits/sigthread.h
cgigranska/wwwmain.o: /usr/include/bits/signal_ext.h
cgigranska/wwwmain.o: /usr/include/bits/waitflags.h
cgigranska/wwwmain.o: /usr/include/bits/waitstatus.h
cgigranska/wwwmain.o: /usr/include/bits/types/idtype_t.h
cgigranska/wwwmain.o: cgigranska/wwwscrutinizer.h scrut/scrutinizer.h
cgigranska/wwwmain.o: scrut/matching.h tagger/wordtoken.h tagger/letter.h
cgigranska/wwwmain.o: /usr/include/string.h
cgigranska/wwwmain.o: /usr/include/bits/libc-header-start.h
cgigranska/wwwmain.o: /usr/include/bits/types/locale_t.h
cgigranska/wwwmain.o: /usr/include/bits/types/__locale_t.h
cgigranska/wwwmain.o: /usr/include/strings.h /usr/include/ctype.h
cgigranska/wwwmain.o: common/basics.h /usr/include/stdio.h
cgigranska/wwwmain.o: /usr/include/bits/types/__fpos_t.h
cgigranska/wwwmain.o: /usr/include/bits/types/__mbstate_t.h
cgigranska/wwwmain.o: /usr/include/bits/types/__fpos64_t.h
cgigranska/wwwmain.o: /usr/include/bits/types/__FILE.h
cgigranska/wwwmain.o: /usr/include/bits/types/FILE.h
cgigranska/wwwmain.o: /usr/include/bits/types/struct_FILE.h
cgigranska/wwwmain.o: /usr/include/bits/types/cookie_io_functions_t.h
cgigranska/wwwmain.o: /usr/include/bits/stdio_lim.h
cgigranska/wwwmain.o: /usr/include/bits/floatn.h
cgigranska/wwwmain.o: /usr/include/bits/floatn-common.h common/ensure.h
cgigranska/wwwmain.o: /usr/include/assert.h tagger/settings.h
cgigranska/wwwmain.o: /usr/include/limits.h /usr/include/bits/posix1_lim.h
cgigranska/wwwmain.o: /usr/include/bits/local_lim.h
cgigranska/wwwmain.o: /usr/include/linux/limits.h
cgigranska/wwwmain.o: /usr/include/bits/pthread_stack_min-dynamic.h
cgigranska/wwwmain.o: /usr/include/bits/pthread_stack_min.h
cgigranska/wwwmain.o: /usr/include/bits/posix2_lim.h common/stringbuf.h
cgigranska/wwwmain.o: tagger/token.h tagger/word.h tagger/hashscatter.h
cgigranska/wwwmain.o: tagger/inflectrule.h common/message.h tagger/tag.h
cgigranska/wwwmain.o: tagger/bitmap.h common/file.h tagger/feature.h
cgigranska/wwwmain.o: tagger/tagdefines.h tagger/wordtag.h scrut/element.h
cgigranska/wwwmain.o: scrut/rule.h common/timer.h /usr/include/sys/time.h
cgigranska/wwwmain.o: tagger/sentence.h tagger/taglexicon.h
cgigranska/wwwmain.o: tagger/hasharray.h tagger/tagtrigram.h
cgigranska/wwwmain.o: scrut/matchingset.h scrut/rules.h tagger/text.h
cgigranska/wwwmain.o: tagger/hashtable.h /usr/include/stdlib.h
cgigranska/wwwmain.o: /usr/include/alloca.h /usr/include/bits/stdlib-float.h
cgigranska/wwwmain.o: scrut/evaluatedvariable.h scrut/semantictype.h
cgigranska/wwwmain.o: scrut/operation.h scrut/expr.h scrut/rulesettings.h
cgigranska/wwwmain.o: scrut/gramerror.h tagger/tagger.h tagger/lexicon.h
cgigranska/wwwmain.o: tagger/morflexicon.h tagger/styleword.h
cgigranska/wwwmain.o: tagger/newwordlexicon.h tagger/newword.h
cgigranska/wwwmain.o: tagger/wordlexicon.h tagger/inflectlexicon.h
cgigranska/wwwmain.o: tagger/wordruleterms.h token/tokenizer.h
cgigranska/wwwmain.o: common/FlexLexer.h tagger/trigramgadget.h
cgigranska/wwwmain.o: scrut/ruleset.h
common/file.o: /usr/include/ctype.h /usr/include/features.h
common/file.o: /usr/include/features-time64.h /usr/include/bits/wordsize.h
common/file.o: /usr/include/bits/timesize.h /usr/include/stdc-predef.h
common/file.o: /usr/include/sys/cdefs.h /usr/include/bits/long-double.h
common/file.o: /usr/include/gnu/stubs.h /usr/include/bits/types.h
common/file.o: /usr/include/bits/typesizes.h /usr/include/bits/time64.h
common/file.o: /usr/include/bits/endian.h /usr/include/bits/endianness.h
common/file.o: /usr/include/bits/types/locale_t.h
common/file.o: /usr/include/bits/types/__locale_t.h /usr/include/string.h
common/file.o: /usr/include/bits/libc-header-start.h /usr/include/strings.h
common/file.o: /usr/include/stdio.h /usr/include/bits/types/__fpos_t.h
common/file.o: /usr/include/bits/types/__mbstate_t.h
common/file.o: /usr/include/bits/types/__fpos64_t.h
common/file.o: /usr/include/bits/types/__FILE.h
common/file.o: /usr/include/bits/types/FILE.h
common/file.o: /usr/include/bits/types/struct_FILE.h
common/file.o: /usr/include/bits/types/cookie_io_functions_t.h
common/file.o: /usr/include/bits/stdio_lim.h /usr/include/bits/floatn.h
common/file.o: /usr/include/bits/floatn-common.h common/file.h
common/file.o: common/ensure.h /usr/include/assert.h common/message.h
common/main.o: scrut/scrutinizer.h scrut/matching.h tagger/wordtoken.h
common/main.o: tagger/letter.h /usr/include/string.h
common/main.o: /usr/include/bits/libc-header-start.h /usr/include/features.h
common/main.o: /usr/include/features-time64.h /usr/include/bits/wordsize.h
common/main.o: /usr/include/bits/timesize.h /usr/include/stdc-predef.h
common/main.o: /usr/include/sys/cdefs.h /usr/include/bits/long-double.h
common/main.o: /usr/include/gnu/stubs.h /usr/include/bits/types/locale_t.h
common/main.o: /usr/include/bits/types/__locale_t.h /usr/include/strings.h
common/main.o: /usr/include/ctype.h /usr/include/bits/types.h
common/main.o: /usr/include/bits/typesizes.h /usr/include/bits/time64.h
common/main.o: /usr/include/bits/endian.h /usr/include/bits/endianness.h
common/main.o: common/basics.h /usr/include/stdio.h
common/main.o: /usr/include/bits/types/__fpos_t.h
common/main.o: /usr/include/bits/types/__mbstate_t.h
common/main.o: /usr/include/bits/types/__fpos64_t.h
common/main.o: /usr/include/bits/types/__FILE.h
common/main.o: /usr/include/bits/types/FILE.h
common/main.o: /usr/include/bits/types/struct_FILE.h
common/main.o: /usr/include/bits/types/cookie_io_functions_t.h
common/main.o: /usr/include/bits/stdio_lim.h /usr/include/bits/floatn.h
common/main.o: /usr/include/bits/floatn-common.h common/ensure.h
common/main.o: /usr/include/assert.h tagger/settings.h /usr/include/limits.h
common/main.o: /usr/include/bits/posix1_lim.h /usr/include/bits/local_lim.h
common/main.o: /usr/include/linux/limits.h
common/main.o: /usr/include/bits/pthread_stack_min-dynamic.h
common/main.o: /usr/include/bits/pthread_stack_min.h
common/main.o: /usr/include/bits/posix2_lim.h common/stringbuf.h
common/main.o: tagger/token.h tagger/word.h tagger/hashscatter.h
common/main.o: tagger/inflectrule.h common/message.h tagger/tag.h
common/main.o: tagger/bitmap.h common/file.h tagger/feature.h
common/main.o: tagger/tagdefines.h tagger/wordtag.h scrut/element.h
common/main.o: scrut/rule.h common/timer.h /usr/include/sys/time.h
common/main.o: /usr/include/bits/types/time_t.h
common/main.o: /usr/include/bits/types/struct_timeval.h
common/main.o: /usr/include/sys/select.h /usr/include/bits/select.h
common/main.o: /usr/include/bits/types/sigset_t.h
common/main.o: /usr/include/bits/types/__sigset_t.h
common/main.o: /usr/include/bits/types/struct_timespec.h tagger/sentence.h
common/main.o: tagger/taglexicon.h tagger/hasharray.h tagger/tagtrigram.h
common/main.o: scrut/matchingset.h scrut/rules.h tagger/text.h
common/main.o: tagger/hashtable.h /usr/include/stdlib.h
common/main.o: /usr/include/sys/types.h /usr/include/bits/types/clock_t.h
common/main.o: /usr/include/bits/types/clockid_t.h
common/main.o: /usr/include/bits/types/timer_t.h
common/main.o: /usr/include/bits/stdint-intn.h /usr/include/endian.h
common/main.o: /usr/include/bits/byteswap.h
common/main.o: /usr/include/bits/uintn-identity.h
common/main.o: /usr/include/bits/pthreadtypes.h
common/main.o: /usr/include/bits/thread-shared-types.h
common/main.o: /usr/include/bits/pthreadtypes-arch.h
common/main.o: /usr/include/bits/atomic_wide_counter.h
common/main.o: /usr/include/bits/struct_mutex.h
common/main.o: /usr/include/bits/struct_rwlock.h /usr/include/alloca.h
common/main.o: /usr/include/bits/stdlib-float.h scrut/evaluatedvariable.h
common/main.o: scrut/semantictype.h scrut/operation.h scrut/expr.h
common/main.o: scrut/rulesettings.h scrut/gramerror.h tagger/tagger.h
common/main.o: tagger/lexicon.h tagger/morflexicon.h tagger/styleword.h
common/main.o: tagger/newwordlexicon.h tagger/newword.h tagger/wordlexicon.h
common/main.o: tagger/inflectlexicon.h tagger/wordruleterms.h
common/main.o: token/tokenizer.h common/FlexLexer.h tagger/trigramgadget.h
common/main.o: scrut/ruleset.h prob/prob.h prob/output.h ../misc/xmloutput.h
common/main.o: prob/config.h prob/probdefines.h
common/message.o: common/message.h tagger/settings.h common/basics.h
common/message.o: /usr/include/stdio.h /usr/include/bits/libc-header-start.h
common/message.o: /usr/include/features.h /usr/include/features-time64.h
common/message.o: /usr/include/bits/wordsize.h /usr/include/bits/timesize.h
common/message.o: /usr/include/stdc-predef.h /usr/include/sys/cdefs.h
common/message.o: /usr/include/bits/long-double.h /usr/include/gnu/stubs.h
common/message.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
common/message.o: /usr/include/bits/time64.h
common/message.o: /usr/include/bits/types/__fpos_t.h
common/message.o: /usr/include/bits/types/__mbstate_t.h
common/message.o: /usr/include/bits/types/__fpos64_t.h
common/message.o: /usr/include/bits/types/__FILE.h
common/message.o: /usr/include/bits/types/FILE.h
common/message.o: /usr/include/bits/types/struct_FILE.h
common/message.o: /usr/include/bits/types/cookie_io_functions_t.h
common/message.o: /usr/include/bits/stdio_lim.h /usr/include/bits/floatn.h
common/message.o: /usr/include/bits/floatn-common.h common/ensure.h
common/message.o: /usr/include/assert.h /usr/include/limits.h
common/message.o: /usr/include/bits/posix1_lim.h
common/message.o: /usr/include/bits/local_lim.h /usr/include/linux/limits.h
common/message.o: /usr/include/bits/pthread_stack_min-dynamic.h
common/message.o: /usr/include/bits/pthread_stack_min.h
common/message.o: /usr/include/bits/posix2_lim.h tagger/sentence.h
common/message.o: tagger/wordtoken.h tagger/letter.h /usr/include/string.h
common/message.o: /usr/include/bits/types/locale_t.h
common/message.o: /usr/include/bits/types/__locale_t.h /usr/include/strings.h
common/message.o: /usr/include/ctype.h /usr/include/bits/endian.h
common/message.o: /usr/include/bits/endianness.h common/stringbuf.h
common/message.o: tagger/token.h tagger/word.h tagger/hashscatter.h
common/message.o: tagger/inflectrule.h tagger/tag.h tagger/bitmap.h
common/message.o: common/file.h tagger/feature.h tagger/tagdefines.h
common/message.o: tagger/wordtag.h
developers-tagger/developers-tagger.o: /usr/include/math.h
developers-tagger/developers-tagger.o: /usr/include/bits/libc-header-start.h
developers-tagger/developers-tagger.o: /usr/include/features.h
developers-tagger/developers-tagger.o: /usr/include/features-time64.h
developers-tagger/developers-tagger.o: /usr/include/bits/wordsize.h
developers-tagger/developers-tagger.o: /usr/include/bits/timesize.h
developers-tagger/developers-tagger.o: /usr/include/stdc-predef.h
developers-tagger/developers-tagger.o: /usr/include/sys/cdefs.h
developers-tagger/developers-tagger.o: /usr/include/bits/long-double.h
developers-tagger/developers-tagger.o: /usr/include/gnu/stubs.h
developers-tagger/developers-tagger.o: /usr/include/bits/types.h
developers-tagger/developers-tagger.o: /usr/include/bits/typesizes.h
developers-tagger/developers-tagger.o: /usr/include/bits/time64.h
developers-tagger/developers-tagger.o: /usr/include/bits/math-vector.h
developers-tagger/developers-tagger.o: /usr/include/bits/libm-simd-decl-stubs.h
developers-tagger/developers-tagger.o: /usr/include/bits/floatn.h
developers-tagger/developers-tagger.o: /usr/include/bits/floatn-common.h
developers-tagger/developers-tagger.o: /usr/include/bits/flt-eval-method.h
developers-tagger/developers-tagger.o: /usr/include/bits/fp-logb.h
developers-tagger/developers-tagger.o: /usr/include/bits/fp-fast.h
developers-tagger/developers-tagger.o: /usr/include/bits/mathcalls-macros.h
developers-tagger/developers-tagger.o: /usr/include/bits/mathcalls-helper-functions.h
developers-tagger/developers-tagger.o: /usr/include/bits/mathcalls.h
developers-tagger/developers-tagger.o: /usr/include/bits/mathcalls-narrow.h
developers-tagger/developers-tagger.o: /usr/include/bits/iscanonical.h
developers-tagger/developers-tagger.o: /usr/include/time.h
developers-tagger/developers-tagger.o: /usr/include/bits/time.h
developers-tagger/developers-tagger.o: /usr/include/bits/types/clock_t.h
developers-tagger/developers-tagger.o: /usr/include/bits/types/time_t.h
developers-tagger/developers-tagger.o: /usr/include/bits/types/struct_tm.h
developers-tagger/developers-tagger.o: /usr/include/bits/types/struct_timespec.h
developers-tagger/developers-tagger.o: /usr/include/bits/endian.h
developers-tagger/developers-tagger.o: /usr/include/bits/endianness.h
developers-tagger/developers-tagger.o: /usr/include/bits/types/clockid_t.h
developers-tagger/developers-tagger.o: /usr/include/bits/types/timer_t.h
developers-tagger/developers-tagger.o: /usr/include/bits/types/struct_itimerspec.h
developers-tagger/developers-tagger.o: /usr/include/bits/types/locale_t.h
developers-tagger/developers-tagger.o: /usr/include/bits/types/__locale_t.h
developers-tagger/developers-tagger.o: developers-tagger/developers-tagger.h
developers-tagger/developers-tagger.o: tagger/tagger.h common/basics.h
developers-tagger/developers-tagger.o: /usr/include/stdio.h
developers-tagger/developers-tagger.o: /usr/include/bits/types/__fpos_t.h
developers-tagger/developers-tagger.o: /usr/include/bits/types/__mbstate_t.h
developers-tagger/developers-tagger.o: /usr/include/bits/types/__fpos64_t.h
developers-tagger/developers-tagger.o: /usr/include/bits/types/__FILE.h
developers-tagger/developers-tagger.o: /usr/include/bits/types/FILE.h
developers-tagger/developers-tagger.o: /usr/include/bits/types/struct_FILE.h
developers-tagger/developers-tagger.o: /usr/include/bits/types/cookie_io_functions_t.h
developers-tagger/developers-tagger.o: /usr/include/bits/stdio_lim.h
developers-tagger/developers-tagger.o: common/ensure.h /usr/include/assert.h
developers-tagger/developers-tagger.o: tagger/lexicon.h tagger/hashtable.h
developers-tagger/developers-tagger.o: /usr/include/string.h
developers-tagger/developers-tagger.o: /usr/include/strings.h
developers-tagger/developers-tagger.o: /usr/include/stdlib.h
developers-tagger/developers-tagger.o: /usr/include/sys/types.h
developers-tagger/developers-tagger.o: /usr/include/bits/stdint-intn.h
developers-tagger/developers-tagger.o: /usr/include/endian.h
developers-tagger/developers-tagger.o: /usr/include/bits/byteswap.h
developers-tagger/developers-tagger.o: /usr/include/bits/uintn-identity.h
developers-tagger/developers-tagger.o: /usr/include/sys/select.h
developers-tagger/developers-tagger.o: /usr/include/bits/select.h
developers-tagger/developers-tagger.o: /usr/include/bits/types/sigset_t.h
developers-tagger/developers-tagger.o: /usr/include/bits/types/__sigset_t.h
developers-tagger/developers-tagger.o: /usr/include/bits/types/struct_timeval.h
developers-tagger/developers-tagger.o: /usr/include/bits/pthreadtypes.h
developers-tagger/developers-tagger.o: /usr/include/bits/thread-shared-types.h
developers-tagger/developers-tagger.o: /usr/include/bits/pthreadtypes-arch.h
developers-tagger/developers-tagger.o: /usr/include/bits/atomic_wide_counter.h
developers-tagger/developers-tagger.o: /usr/include/bits/struct_mutex.h
developers-tagger/developers-tagger.o: /usr/include/bits/struct_rwlock.h
developers-tagger/developers-tagger.o: /usr/include/alloca.h
developers-tagger/developers-tagger.o: /usr/include/bits/stdlib-float.h
developers-tagger/developers-tagger.o: tagger/morflexicon.h tagger/word.h
developers-tagger/developers-tagger.o: tagger/hashscatter.h
developers-tagger/developers-tagger.o: tagger/inflectrule.h
developers-tagger/developers-tagger.o: /usr/include/limits.h
developers-tagger/developers-tagger.o: /usr/include/bits/posix1_lim.h
developers-tagger/developers-tagger.o: /usr/include/bits/local_lim.h
developers-tagger/developers-tagger.o: /usr/include/linux/limits.h
developers-tagger/developers-tagger.o: /usr/include/bits/pthread_stack_min-dynamic.h
developers-tagger/developers-tagger.o: /usr/include/bits/pthread_stack_min.h
developers-tagger/developers-tagger.o: /usr/include/bits/posix2_lim.h
developers-tagger/developers-tagger.o: common/message.h tagger/tag.h
developers-tagger/developers-tagger.o: tagger/bitmap.h common/file.h
developers-tagger/developers-tagger.o: /usr/include/ctype.h tagger/feature.h
developers-tagger/developers-tagger.o: tagger/settings.h tagger/tagdefines.h
developers-tagger/developers-tagger.o: tagger/wordtag.h common/stringbuf.h
developers-tagger/developers-tagger.o: tagger/hasharray.h tagger/taglexicon.h
developers-tagger/developers-tagger.o: tagger/tagtrigram.h tagger/token.h
developers-tagger/developers-tagger.o: tagger/styleword.h
developers-tagger/developers-tagger.o: tagger/newwordlexicon.h
developers-tagger/developers-tagger.o: tagger/newword.h tagger/wordlexicon.h
developers-tagger/developers-tagger.o: tagger/inflectlexicon.h
developers-tagger/developers-tagger.o: tagger/wordruleterms.h
developers-tagger/developers-tagger.o: tagger/sentence.h tagger/wordtoken.h
developers-tagger/developers-tagger.o: tagger/letter.h common/timer.h
developers-tagger/developers-tagger.o: /usr/include/sys/time.h tagger/text.h
developers-tagger/developers-tagger.o: token/tokenizer.h common/FlexLexer.h
developers-tagger/developers-tagger.o: tagger/trigramgadget.h tagger/morf.h
developers-tagger/developers-tagger.o: developers-tagger/settings_manip.h
developers-tagger/developers-tagger.o: tagger/heap.h
developers-tagger/main.o: tagger/settings.h common/basics.h
developers-tagger/main.o: /usr/include/stdio.h
developers-tagger/main.o: /usr/include/bits/libc-header-start.h
developers-tagger/main.o: /usr/include/features.h
developers-tagger/main.o: /usr/include/features-time64.h
developers-tagger/main.o: /usr/include/bits/wordsize.h
developers-tagger/main.o: /usr/include/bits/timesize.h
developers-tagger/main.o: /usr/include/stdc-predef.h /usr/include/sys/cdefs.h
developers-tagger/main.o: /usr/include/bits/long-double.h
developers-tagger/main.o: /usr/include/gnu/stubs.h /usr/include/bits/types.h
developers-tagger/main.o: /usr/include/bits/typesizes.h
developers-tagger/main.o: /usr/include/bits/time64.h
developers-tagger/main.o: /usr/include/bits/types/__fpos_t.h
developers-tagger/main.o: /usr/include/bits/types/__mbstate_t.h
developers-tagger/main.o: /usr/include/bits/types/__fpos64_t.h
developers-tagger/main.o: /usr/include/bits/types/__FILE.h
developers-tagger/main.o: /usr/include/bits/types/FILE.h
developers-tagger/main.o: /usr/include/bits/types/struct_FILE.h
developers-tagger/main.o: /usr/include/bits/types/cookie_io_functions_t.h
developers-tagger/main.o: /usr/include/bits/stdio_lim.h
developers-tagger/main.o: /usr/include/bits/floatn.h
developers-tagger/main.o: /usr/include/bits/floatn-common.h common/ensure.h
developers-tagger/main.o: /usr/include/assert.h /usr/include/limits.h
developers-tagger/main.o: /usr/include/bits/posix1_lim.h
developers-tagger/main.o: /usr/include/bits/local_lim.h
developers-tagger/main.o: /usr/include/linux/limits.h
developers-tagger/main.o: /usr/include/bits/pthread_stack_min-dynamic.h
developers-tagger/main.o: /usr/include/bits/pthread_stack_min.h
developers-tagger/main.o: /usr/include/bits/posix2_lim.h common/file.h
developers-tagger/main.o: /usr/include/ctype.h /usr/include/bits/endian.h
developers-tagger/main.o: /usr/include/bits/endianness.h
developers-tagger/main.o: /usr/include/bits/types/locale_t.h
developers-tagger/main.o: /usr/include/bits/types/__locale_t.h
developers-tagger/main.o: common/message.h tagger/letter.h
developers-tagger/main.o: /usr/include/string.h /usr/include/strings.h
developers-tagger/main.o: developers-tagger/developers-tagger.h
developers-tagger/main.o: tagger/tagger.h tagger/lexicon.h tagger/hashtable.h
developers-tagger/main.o: /usr/include/stdlib.h /usr/include/sys/types.h
developers-tagger/main.o: /usr/include/bits/types/clock_t.h
developers-tagger/main.o: /usr/include/bits/types/clockid_t.h
developers-tagger/main.o: /usr/include/bits/types/time_t.h
developers-tagger/main.o: /usr/include/bits/types/timer_t.h
developers-tagger/main.o: /usr/include/bits/stdint-intn.h
developers-tagger/main.o: /usr/include/endian.h /usr/include/bits/byteswap.h
developers-tagger/main.o: /usr/include/bits/uintn-identity.h
developers-tagger/main.o: /usr/include/sys/select.h
developers-tagger/main.o: /usr/include/bits/select.h
developers-tagger/main.o: /usr/include/bits/types/sigset_t.h
developers-tagger/main.o: /usr/include/bits/types/__sigset_t.h
developers-tagger/main.o: /usr/include/bits/types/struct_timeval.h
developers-tagger/main.o: /usr/include/bits/types/struct_timespec.h
developers-tagger/main.o: /usr/include/bits/pthreadtypes.h
developers-tagger/main.o: /usr/include/bits/thread-shared-types.h
developers-tagger/main.o: /usr/include/bits/pthreadtypes-arch.h
developers-tagger/main.o: /usr/include/bits/atomic_wide_counter.h
developers-tagger/main.o: /usr/include/bits/struct_mutex.h
developers-tagger/main.o: /usr/include/bits/struct_rwlock.h
developers-tagger/main.o: /usr/include/alloca.h
developers-tagger/main.o: /usr/include/bits/stdlib-float.h
developers-tagger/main.o: tagger/morflexicon.h tagger/word.h
developers-tagger/main.o: tagger/hashscatter.h tagger/inflectrule.h
developers-tagger/main.o: tagger/tag.h tagger/bitmap.h tagger/feature.h
developers-tagger/main.o: tagger/tagdefines.h tagger/wordtag.h
developers-tagger/main.o: common/stringbuf.h tagger/hasharray.h
developers-tagger/main.o: tagger/taglexicon.h tagger/tagtrigram.h
developers-tagger/main.o: tagger/token.h tagger/styleword.h
developers-tagger/main.o: tagger/newwordlexicon.h tagger/newword.h
developers-tagger/main.o: tagger/wordlexicon.h tagger/inflectlexicon.h
developers-tagger/main.o: tagger/wordruleterms.h tagger/sentence.h
developers-tagger/main.o: tagger/wordtoken.h common/timer.h
developers-tagger/main.o: /usr/include/sys/time.h tagger/text.h
developers-tagger/main.o: token/tokenizer.h common/FlexLexer.h
developers-tagger/main.o: tagger/trigramgadget.h
developers-tagger/main.o: developers-tagger/settings_manip.h
developers-tagger/settings_manip.o: developers-tagger/settings_manip.h
developers-tagger/settings_manip.o: common/message.h common/file.h
developers-tagger/settings_manip.o: /usr/include/ctype.h
developers-tagger/settings_manip.o: /usr/include/features.h
developers-tagger/settings_manip.o: /usr/include/features-time64.h
developers-tagger/settings_manip.o: /usr/include/bits/wordsize.h
developers-tagger/settings_manip.o: /usr/include/bits/timesize.h
developers-tagger/settings_manip.o: /usr/include/stdc-predef.h
developers-tagger/settings_manip.o: /usr/include/sys/cdefs.h
developers-tagger/settings_manip.o: /usr/include/bits/long-double.h
developers-tagger/settings_manip.o: /usr/include/gnu/stubs.h
developers-tagger/settings_manip.o: /usr/include/bits/types.h
developers-tagger/settings_manip.o: /usr/include/bits/typesizes.h
developers-tagger/settings_manip.o: /usr/include/bits/time64.h
developers-tagger/settings_manip.o: /usr/include/bits/endian.h
developers-tagger/settings_manip.o: /usr/include/bits/endianness.h
developers-tagger/settings_manip.o: /usr/include/bits/types/locale_t.h
developers-tagger/settings_manip.o: /usr/include/bits/types/__locale_t.h
developers-tagger/settings_manip.o: common/ensure.h /usr/include/assert.h
developers-tagger/settings_manip.o: tagger/settings.h common/basics.h
developers-tagger/settings_manip.o: /usr/include/stdio.h
developers-tagger/settings_manip.o: /usr/include/bits/libc-header-start.h
developers-tagger/settings_manip.o: /usr/include/bits/types/__fpos_t.h
developers-tagger/settings_manip.o: /usr/include/bits/types/__mbstate_t.h
developers-tagger/settings_manip.o: /usr/include/bits/types/__fpos64_t.h
developers-tagger/settings_manip.o: /usr/include/bits/types/__FILE.h
developers-tagger/settings_manip.o: /usr/include/bits/types/FILE.h
developers-tagger/settings_manip.o: /usr/include/bits/types/struct_FILE.h
developers-tagger/settings_manip.o: /usr/include/bits/types/cookie_io_functions_t.h
developers-tagger/settings_manip.o: /usr/include/bits/stdio_lim.h
developers-tagger/settings_manip.o: /usr/include/bits/floatn.h
developers-tagger/settings_manip.o: /usr/include/bits/floatn-common.h
developers-tagger/settings_manip.o: /usr/include/limits.h
developers-tagger/settings_manip.o: /usr/include/bits/posix1_lim.h
developers-tagger/settings_manip.o: /usr/include/bits/local_lim.h
developers-tagger/settings_manip.o: /usr/include/linux/limits.h
developers-tagger/settings_manip.o: /usr/include/bits/pthread_stack_min-dynamic.h
developers-tagger/settings_manip.o: /usr/include/bits/pthread_stack_min.h
developers-tagger/settings_manip.o: /usr/include/bits/posix2_lim.h
prob/annot.o: prob/annot.h tagger/sentence.h tagger/wordtoken.h
prob/annot.o: tagger/letter.h /usr/include/string.h
prob/annot.o: /usr/include/bits/libc-header-start.h /usr/include/features.h
prob/annot.o: /usr/include/features-time64.h /usr/include/bits/wordsize.h
prob/annot.o: /usr/include/bits/timesize.h /usr/include/stdc-predef.h
prob/annot.o: /usr/include/sys/cdefs.h /usr/include/bits/long-double.h
prob/annot.o: /usr/include/gnu/stubs.h /usr/include/bits/types/locale_t.h
prob/annot.o: /usr/include/bits/types/__locale_t.h /usr/include/strings.h
prob/annot.o: /usr/include/ctype.h /usr/include/bits/types.h
prob/annot.o: /usr/include/bits/typesizes.h /usr/include/bits/time64.h
prob/annot.o: /usr/include/bits/endian.h /usr/include/bits/endianness.h
prob/annot.o: common/basics.h /usr/include/stdio.h
prob/annot.o: /usr/include/bits/types/__fpos_t.h
prob/annot.o: /usr/include/bits/types/__mbstate_t.h
prob/annot.o: /usr/include/bits/types/__fpos64_t.h
prob/annot.o: /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h
prob/annot.o: /usr/include/bits/types/struct_FILE.h
prob/annot.o: /usr/include/bits/types/cookie_io_functions_t.h
prob/annot.o: /usr/include/bits/stdio_lim.h /usr/include/bits/floatn.h
prob/annot.o: /usr/include/bits/floatn-common.h common/ensure.h
prob/annot.o: /usr/include/assert.h tagger/settings.h /usr/include/limits.h
prob/annot.o: /usr/include/bits/posix1_lim.h /usr/include/bits/local_lim.h
prob/annot.o: /usr/include/linux/limits.h
prob/annot.o: /usr/include/bits/pthread_stack_min-dynamic.h
prob/annot.o: /usr/include/bits/pthread_stack_min.h
prob/annot.o: /usr/include/bits/posix2_lim.h common/stringbuf.h
prob/annot.o: tagger/token.h tagger/word.h tagger/hashscatter.h
prob/annot.o: tagger/inflectrule.h common/message.h tagger/tag.h
prob/annot.o: tagger/bitmap.h common/file.h tagger/feature.h
prob/annot.o: tagger/tagdefines.h tagger/wordtag.h prob/domerror.h
prob/client.o: prob/probadmin.h prob/prob.h prob/defines.h
prob/client.o: tagger/tagdefines.h prob/probdefines.h
prob/output.o: ../misc/xmloutput.h prob/output.h prob/defines.h
prob/pipe_client.o: /usr/include/stdio.h
prob/pipe_client.o: /usr/include/bits/libc-header-start.h
prob/pipe_client.o: /usr/include/features.h /usr/include/features-time64.h
prob/pipe_client.o: /usr/include/bits/wordsize.h /usr/include/bits/timesize.h
prob/pipe_client.o: /usr/include/stdc-predef.h /usr/include/sys/cdefs.h
prob/pipe_client.o: /usr/include/bits/long-double.h /usr/include/gnu/stubs.h
prob/pipe_client.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
prob/pipe_client.o: /usr/include/bits/time64.h
prob/pipe_client.o: /usr/include/bits/types/__fpos_t.h
prob/pipe_client.o: /usr/include/bits/types/__mbstate_t.h
prob/pipe_client.o: /usr/include/bits/types/__fpos64_t.h
prob/pipe_client.o: /usr/include/bits/types/__FILE.h
prob/pipe_client.o: /usr/include/bits/types/FILE.h
prob/pipe_client.o: /usr/include/bits/types/struct_FILE.h
prob/pipe_client.o: /usr/include/bits/types/cookie_io_functions_t.h
prob/pipe_client.o: /usr/include/bits/stdio_lim.h /usr/include/bits/floatn.h
prob/pipe_client.o: /usr/include/bits/floatn-common.h prob/pipe_client.h
prob/probadmin.o: prob/probadmin.h prob/prob.h prob/defines.h
prob/probadmin.o: tagger/tagdefines.h prob/probdefines.h tagger/taglexicon.h
prob/probadmin.o: tagger/bitmap.h common/basics.h /usr/include/stdio.h
prob/probadmin.o: /usr/include/bits/libc-header-start.h
prob/probadmin.o: /usr/include/features.h /usr/include/features-time64.h
prob/probadmin.o: /usr/include/bits/wordsize.h /usr/include/bits/timesize.h
prob/probadmin.o: /usr/include/stdc-predef.h /usr/include/sys/cdefs.h
prob/probadmin.o: /usr/include/bits/long-double.h /usr/include/gnu/stubs.h
prob/probadmin.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
prob/probadmin.o: /usr/include/bits/time64.h
prob/probadmin.o: /usr/include/bits/types/__fpos_t.h
prob/probadmin.o: /usr/include/bits/types/__mbstate_t.h
prob/probadmin.o: /usr/include/bits/types/__fpos64_t.h
prob/probadmin.o: /usr/include/bits/types/__FILE.h
prob/probadmin.o: /usr/include/bits/types/FILE.h
prob/probadmin.o: /usr/include/bits/types/struct_FILE.h
prob/probadmin.o: /usr/include/bits/types/cookie_io_functions_t.h
prob/probadmin.o: /usr/include/bits/stdio_lim.h /usr/include/bits/floatn.h
prob/probadmin.o: /usr/include/bits/floatn-common.h common/ensure.h
prob/probadmin.o: /usr/include/assert.h common/file.h /usr/include/ctype.h
prob/probadmin.o: /usr/include/bits/endian.h /usr/include/bits/endianness.h
prob/probadmin.o: /usr/include/bits/types/locale_t.h
prob/probadmin.o: /usr/include/bits/types/__locale_t.h common/message.h
prob/probadmin.o: tagger/feature.h tagger/hasharray.h tagger/tag.h
prob/probadmin.o: /usr/include/string.h /usr/include/strings.h
prob/probadmin.o: tagger/hashscatter.h tagger/settings.h
prob/probadmin.o: /usr/include/limits.h /usr/include/bits/posix1_lim.h
prob/probadmin.o: /usr/include/bits/local_lim.h /usr/include/linux/limits.h
prob/probadmin.o: /usr/include/bits/pthread_stack_min-dynamic.h
prob/probadmin.o: /usr/include/bits/pthread_stack_min.h
prob/probadmin.o: /usr/include/bits/posix2_lim.h tagger/tagtrigram.h
prob/probadmin.o: tagger/token.h tagger/word.h tagger/inflectrule.h
prob/probadmin.o: tagger/wordtag.h common/stringbuf.h prob/annot.h
prob/probadmin.o: prob/config.h prob/probdevelop.h prob/output.h
prob/probadmin.o: ../misc/xmloutput.h prob/report.h prob/probinfo.h
prob/probadmin.o: prob/probmatch.h scrut/matching.h tagger/wordtoken.h
prob/probadmin.o: tagger/letter.h scrut/element.h scrut/rule.h common/timer.h
prob/probadmin.o: /usr/include/sys/time.h /usr/include/bits/types/time_t.h
prob/probadmin.o: /usr/include/bits/types/struct_timeval.h
prob/probadmin.o: /usr/include/sys/select.h /usr/include/bits/select.h
prob/probadmin.o: /usr/include/bits/types/sigset_t.h
prob/probadmin.o: /usr/include/bits/types/__sigset_t.h
prob/probadmin.o: /usr/include/bits/types/struct_timespec.h tagger/sentence.h
prob/probcheck.o: prob/probcheck.h scrut/scrutinizer.h scrut/matching.h
prob/probcheck.o: tagger/wordtoken.h tagger/letter.h /usr/include/string.h
prob/probcheck.o: /usr/include/bits/libc-header-start.h
prob/probcheck.o: /usr/include/features.h /usr/include/features-time64.h
prob/probcheck.o: /usr/include/bits/wordsize.h /usr/include/bits/timesize.h
prob/probcheck.o: /usr/include/stdc-predef.h /usr/include/sys/cdefs.h
prob/probcheck.o: /usr/include/bits/long-double.h /usr/include/gnu/stubs.h
prob/probcheck.o: /usr/include/bits/types/locale_t.h
prob/probcheck.o: /usr/include/bits/types/__locale_t.h /usr/include/strings.h
prob/probcheck.o: /usr/include/ctype.h /usr/include/bits/types.h
prob/probcheck.o: /usr/include/bits/typesizes.h /usr/include/bits/time64.h
prob/probcheck.o: /usr/include/bits/endian.h /usr/include/bits/endianness.h
prob/probcheck.o: common/basics.h /usr/include/stdio.h
prob/probcheck.o: /usr/include/bits/types/__fpos_t.h
prob/probcheck.o: /usr/include/bits/types/__mbstate_t.h
prob/probcheck.o: /usr/include/bits/types/__fpos64_t.h
prob/probcheck.o: /usr/include/bits/types/__FILE.h
prob/probcheck.o: /usr/include/bits/types/FILE.h
prob/probcheck.o: /usr/include/bits/types/struct_FILE.h
prob/probcheck.o: /usr/include/bits/types/cookie_io_functions_t.h
prob/probcheck.o: /usr/include/bits/stdio_lim.h /usr/include/bits/floatn.h
prob/probcheck.o: /usr/include/bits/floatn-common.h common/ensure.h
prob/probcheck.o: /usr/include/assert.h tagger/settings.h
prob/probcheck.o: /usr/include/limits.h /usr/include/bits/posix1_lim.h
prob/probcheck.o: /usr/include/bits/local_lim.h /usr/include/linux/limits.h
prob/probcheck.o: /usr/include/bits/pthread_stack_min-dynamic.h
prob/probcheck.o: /usr/include/bits/pthread_stack_min.h
prob/probcheck.o: /usr/include/bits/posix2_lim.h common/stringbuf.h
prob/probcheck.o: tagger/token.h tagger/word.h tagger/hashscatter.h
prob/probcheck.o: tagger/inflectrule.h common/message.h tagger/tag.h
prob/probcheck.o: tagger/bitmap.h common/file.h tagger/feature.h
prob/probcheck.o: tagger/tagdefines.h tagger/wordtag.h scrut/element.h
prob/probcheck.o: scrut/rule.h common/timer.h /usr/include/sys/time.h
prob/probcheck.o: /usr/include/bits/types/time_t.h
prob/probcheck.o: /usr/include/bits/types/struct_timeval.h
prob/probcheck.o: /usr/include/sys/select.h /usr/include/bits/select.h
prob/probcheck.o: /usr/include/bits/types/sigset_t.h
prob/probcheck.o: /usr/include/bits/types/__sigset_t.h
prob/probcheck.o: /usr/include/bits/types/struct_timespec.h tagger/sentence.h
prob/probcheck.o: tagger/taglexicon.h tagger/hasharray.h tagger/tagtrigram.h
prob/probcheck.o: scrut/matchingset.h scrut/rules.h tagger/text.h
prob/probcheck.o: tagger/hashtable.h /usr/include/stdlib.h
prob/probcheck.o: /usr/include/sys/types.h /usr/include/bits/types/clock_t.h
prob/probcheck.o: /usr/include/bits/types/clockid_t.h
prob/probcheck.o: /usr/include/bits/types/timer_t.h
prob/probcheck.o: /usr/include/bits/stdint-intn.h /usr/include/endian.h
prob/probcheck.o: /usr/include/bits/byteswap.h
prob/probcheck.o: /usr/include/bits/uintn-identity.h
prob/probcheck.o: /usr/include/bits/pthreadtypes.h
prob/probcheck.o: /usr/include/bits/thread-shared-types.h
prob/probcheck.o: /usr/include/bits/pthreadtypes-arch.h
prob/probcheck.o: /usr/include/bits/atomic_wide_counter.h
prob/probcheck.o: /usr/include/bits/struct_mutex.h
prob/probcheck.o: /usr/include/bits/struct_rwlock.h /usr/include/alloca.h
prob/probcheck.o: /usr/include/bits/stdlib-float.h scrut/evaluatedvariable.h
prob/probcheck.o: scrut/semantictype.h scrut/operation.h scrut/expr.h
prob/probcheck.o: scrut/rulesettings.h scrut/gramerror.h tagger/tagger.h
prob/probcheck.o: tagger/lexicon.h tagger/morflexicon.h tagger/styleword.h
prob/probcheck.o: tagger/newwordlexicon.h tagger/newword.h
prob/probcheck.o: tagger/wordlexicon.h tagger/inflectlexicon.h
prob/probcheck.o: tagger/wordruleterms.h token/tokenizer.h common/FlexLexer.h
prob/probcheck.o: tagger/trigramgadget.h prob/defines.h prob/config.h
prob/probcheck.o: prob/probdefines.h prob/annot.h prob/report.h
prob/probcheck.o: prob/probinfo.h prob/probmatch.h prob/probadmin.h
prob/probcheck.o: prob/prob.h prob/probdevelop.h prob/output.h
prob/probcheck.o: ../misc/xmloutput.h
prob/probdevelop.o: prob/probdevelop.h prob/output.h ../misc/xmloutput.h
prob/probdevelop.o: prob/probdefines.h
prob/probinfo.o: prob/probinfo.h scrut/scrutinizer.h scrut/matching.h
prob/probinfo.o: tagger/wordtoken.h tagger/letter.h /usr/include/string.h
prob/probinfo.o: /usr/include/bits/libc-header-start.h
prob/probinfo.o: /usr/include/features.h /usr/include/features-time64.h
prob/probinfo.o: /usr/include/bits/wordsize.h /usr/include/bits/timesize.h
prob/probinfo.o: /usr/include/stdc-predef.h /usr/include/sys/cdefs.h
prob/probinfo.o: /usr/include/bits/long-double.h /usr/include/gnu/stubs.h
prob/probinfo.o: /usr/include/bits/types/locale_t.h
prob/probinfo.o: /usr/include/bits/types/__locale_t.h /usr/include/strings.h
prob/probinfo.o: /usr/include/ctype.h /usr/include/bits/types.h
prob/probinfo.o: /usr/include/bits/typesizes.h /usr/include/bits/time64.h
prob/probinfo.o: /usr/include/bits/endian.h /usr/include/bits/endianness.h
prob/probinfo.o: common/basics.h /usr/include/stdio.h
prob/probinfo.o: /usr/include/bits/types/__fpos_t.h
prob/probinfo.o: /usr/include/bits/types/__mbstate_t.h
prob/probinfo.o: /usr/include/bits/types/__fpos64_t.h
prob/probinfo.o: /usr/include/bits/types/__FILE.h
prob/probinfo.o: /usr/include/bits/types/FILE.h
prob/probinfo.o: /usr/include/bits/types/struct_FILE.h
prob/probinfo.o: /usr/include/bits/types/cookie_io_functions_t.h
prob/probinfo.o: /usr/include/bits/stdio_lim.h /usr/include/bits/floatn.h
prob/probinfo.o: /usr/include/bits/floatn-common.h common/ensure.h
prob/probinfo.o: /usr/include/assert.h tagger/settings.h
prob/probinfo.o: /usr/include/limits.h /usr/include/bits/posix1_lim.h
prob/probinfo.o: /usr/include/bits/local_lim.h /usr/include/linux/limits.h
prob/probinfo.o: /usr/include/bits/pthread_stack_min-dynamic.h
prob/probinfo.o: /usr/include/bits/pthread_stack_min.h
prob/probinfo.o: /usr/include/bits/posix2_lim.h common/stringbuf.h
prob/probinfo.o: tagger/token.h tagger/word.h tagger/hashscatter.h
prob/probinfo.o: tagger/inflectrule.h common/message.h tagger/tag.h
prob/probinfo.o: tagger/bitmap.h common/file.h tagger/feature.h
prob/probinfo.o: tagger/tagdefines.h tagger/wordtag.h scrut/element.h
prob/probinfo.o: scrut/rule.h common/timer.h /usr/include/sys/time.h
prob/probinfo.o: /usr/include/bits/types/time_t.h
prob/probinfo.o: /usr/include/bits/types/struct_timeval.h
prob/probinfo.o: /usr/include/sys/select.h /usr/include/bits/select.h
prob/probinfo.o: /usr/include/bits/types/sigset_t.h
prob/probinfo.o: /usr/include/bits/types/__sigset_t.h
prob/probinfo.o: /usr/include/bits/types/struct_timespec.h tagger/sentence.h
prob/probinfo.o: tagger/taglexicon.h tagger/hasharray.h tagger/tagtrigram.h
prob/probinfo.o: scrut/matchingset.h scrut/rules.h tagger/text.h
prob/probinfo.o: tagger/hashtable.h /usr/include/stdlib.h
prob/probinfo.o: /usr/include/sys/types.h /usr/include/bits/types/clock_t.h
prob/probinfo.o: /usr/include/bits/types/clockid_t.h
prob/probinfo.o: /usr/include/bits/types/timer_t.h
prob/probinfo.o: /usr/include/bits/stdint-intn.h /usr/include/endian.h
prob/probinfo.o: /usr/include/bits/byteswap.h
prob/probinfo.o: /usr/include/bits/uintn-identity.h
prob/probinfo.o: /usr/include/bits/pthreadtypes.h
prob/probinfo.o: /usr/include/bits/thread-shared-types.h
prob/probinfo.o: /usr/include/bits/pthreadtypes-arch.h
prob/probinfo.o: /usr/include/bits/atomic_wide_counter.h
prob/probinfo.o: /usr/include/bits/struct_mutex.h
prob/probinfo.o: /usr/include/bits/struct_rwlock.h /usr/include/alloca.h
prob/probinfo.o: /usr/include/bits/stdlib-float.h scrut/evaluatedvariable.h
prob/probinfo.o: scrut/semantictype.h scrut/operation.h scrut/expr.h
prob/probinfo.o: scrut/rulesettings.h scrut/gramerror.h tagger/tagger.h
prob/probinfo.o: tagger/lexicon.h tagger/morflexicon.h tagger/styleword.h
prob/probinfo.o: tagger/newwordlexicon.h tagger/newword.h
prob/probinfo.o: tagger/wordlexicon.h tagger/inflectlexicon.h
prob/probinfo.o: tagger/wordruleterms.h token/tokenizer.h common/FlexLexer.h
prob/probinfo.o: tagger/trigramgadget.h
prob/probmatch.o: prob/probmatch.h prob/probdefines.h prob/probdevelop.h
prob/probmatch.o: prob/output.h ../misc/xmloutput.h tagger/tag.h
prob/probmatch.o: /usr/include/string.h /usr/include/bits/libc-header-start.h
prob/probmatch.o: /usr/include/features.h /usr/include/features-time64.h
prob/probmatch.o: /usr/include/bits/wordsize.h /usr/include/bits/timesize.h
prob/probmatch.o: /usr/include/stdc-predef.h /usr/include/sys/cdefs.h
prob/probmatch.o: /usr/include/bits/long-double.h /usr/include/gnu/stubs.h
prob/probmatch.o: /usr/include/bits/types/locale_t.h
prob/probmatch.o: /usr/include/bits/types/__locale_t.h /usr/include/strings.h
prob/probmatch.o: common/basics.h /usr/include/stdio.h
prob/probmatch.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
prob/probmatch.o: /usr/include/bits/time64.h
prob/probmatch.o: /usr/include/bits/types/__fpos_t.h
prob/probmatch.o: /usr/include/bits/types/__mbstate_t.h
prob/probmatch.o: /usr/include/bits/types/__fpos64_t.h
prob/probmatch.o: /usr/include/bits/types/__FILE.h
prob/probmatch.o: /usr/include/bits/types/FILE.h
prob/probmatch.o: /usr/include/bits/types/struct_FILE.h
prob/probmatch.o: /usr/include/bits/types/cookie_io_functions_t.h
prob/probmatch.o: /usr/include/bits/stdio_lim.h /usr/include/bits/floatn.h
prob/probmatch.o: /usr/include/bits/floatn-common.h common/ensure.h
prob/probmatch.o: /usr/include/assert.h tagger/bitmap.h common/file.h
prob/probmatch.o: /usr/include/ctype.h /usr/include/bits/endian.h
prob/probmatch.o: /usr/include/bits/endianness.h common/message.h
prob/probmatch.o: tagger/feature.h tagger/hashscatter.h tagger/settings.h
prob/probmatch.o: /usr/include/limits.h /usr/include/bits/posix1_lim.h
prob/probmatch.o: /usr/include/bits/local_lim.h /usr/include/linux/limits.h
prob/probmatch.o: /usr/include/bits/pthread_stack_min-dynamic.h
prob/probmatch.o: /usr/include/bits/pthread_stack_min.h
prob/probmatch.o: /usr/include/bits/posix2_lim.h tagger/tagdefines.h
prob/report.o: prob/report.h prob/probinfo.h prob/probmatch.h
prob/report.o: prob/probdefines.h scrut/rule.h common/timer.h
prob/report.o: /usr/include/sys/time.h /usr/include/features.h
prob/report.o: /usr/include/features-time64.h /usr/include/bits/wordsize.h
prob/report.o: /usr/include/bits/timesize.h /usr/include/stdc-predef.h
prob/report.o: /usr/include/sys/cdefs.h /usr/include/bits/long-double.h
prob/report.o: /usr/include/gnu/stubs.h /usr/include/bits/types.h
prob/report.o: /usr/include/bits/typesizes.h /usr/include/bits/time64.h
prob/report.o: /usr/include/bits/types/time_t.h
prob/report.o: /usr/include/bits/types/struct_timeval.h
prob/report.o: /usr/include/sys/select.h /usr/include/bits/select.h
prob/report.o: /usr/include/bits/types/sigset_t.h
prob/report.o: /usr/include/bits/types/__sigset_t.h
prob/report.o: /usr/include/bits/types/struct_timespec.h
prob/report.o: /usr/include/bits/endian.h /usr/include/bits/endianness.h
prob/report.o: tagger/sentence.h tagger/wordtoken.h tagger/letter.h
prob/report.o: /usr/include/string.h /usr/include/bits/libc-header-start.h
prob/report.o: /usr/include/bits/types/locale_t.h
prob/report.o: /usr/include/bits/types/__locale_t.h /usr/include/strings.h
prob/report.o: /usr/include/ctype.h common/basics.h /usr/include/stdio.h
prob/report.o: /usr/include/bits/types/__fpos_t.h
prob/report.o: /usr/include/bits/types/__mbstate_t.h
prob/report.o: /usr/include/bits/types/__fpos64_t.h
prob/report.o: /usr/include/bits/types/__FILE.h
prob/report.o: /usr/include/bits/types/FILE.h
prob/report.o: /usr/include/bits/types/struct_FILE.h
prob/report.o: /usr/include/bits/types/cookie_io_functions_t.h
prob/report.o: /usr/include/bits/stdio_lim.h /usr/include/bits/floatn.h
prob/report.o: /usr/include/bits/floatn-common.h common/ensure.h
prob/report.o: /usr/include/assert.h tagger/settings.h /usr/include/limits.h
prob/report.o: /usr/include/bits/posix1_lim.h /usr/include/bits/local_lim.h
prob/report.o: /usr/include/linux/limits.h
prob/report.o: /usr/include/bits/pthread_stack_min-dynamic.h
prob/report.o: /usr/include/bits/pthread_stack_min.h
prob/report.o: /usr/include/bits/posix2_lim.h common/stringbuf.h
prob/report.o: tagger/token.h tagger/word.h tagger/hashscatter.h
prob/report.o: tagger/inflectrule.h common/message.h tagger/tag.h
prob/report.o: tagger/bitmap.h common/file.h tagger/feature.h
prob/report.o: tagger/tagdefines.h tagger/wordtag.h scrut/element.h
prob/report.o: tagger/taglexicon.h tagger/hasharray.h tagger/tagtrigram.h
prob/report.o: prob/output.h ../misc/xmloutput.h scrut/scrutinizer.h
prob/report.o: scrut/matching.h scrut/matchingset.h scrut/rules.h
prob/report.o: tagger/text.h tagger/hashtable.h /usr/include/stdlib.h
prob/report.o: /usr/include/sys/types.h /usr/include/bits/types/clock_t.h
prob/report.o: /usr/include/bits/types/clockid_t.h
prob/report.o: /usr/include/bits/types/timer_t.h
prob/report.o: /usr/include/bits/stdint-intn.h /usr/include/endian.h
prob/report.o: /usr/include/bits/byteswap.h
prob/report.o: /usr/include/bits/uintn-identity.h
prob/report.o: /usr/include/bits/pthreadtypes.h
prob/report.o: /usr/include/bits/thread-shared-types.h
prob/report.o: /usr/include/bits/pthreadtypes-arch.h
prob/report.o: /usr/include/bits/atomic_wide_counter.h
prob/report.o: /usr/include/bits/struct_mutex.h
prob/report.o: /usr/include/bits/struct_rwlock.h /usr/include/alloca.h
prob/report.o: /usr/include/bits/stdlib-float.h scrut/evaluatedvariable.h
prob/report.o: scrut/semantictype.h scrut/operation.h scrut/expr.h
prob/report.o: scrut/rulesettings.h scrut/gramerror.h tagger/tagger.h
prob/report.o: tagger/lexicon.h tagger/morflexicon.h tagger/styleword.h
prob/report.o: tagger/newwordlexicon.h tagger/newword.h tagger/wordlexicon.h
prob/report.o: tagger/inflectlexicon.h tagger/wordruleterms.h
prob/report.o: token/tokenizer.h common/FlexLexer.h tagger/trigramgadget.h
prob/report.o: scrut/ruleset.h prob/annot.h prob/probdevelop.h
prob/report.o: prob/probadmin.h prob/prob.h prob/defines.h prob/config.h
prob/represent.o: prob/probadmin.h prob/prob.h prob/defines.h
prob/represent.o: tagger/tagdefines.h prob/probdefines.h tagger/taglexicon.h
prob/represent.o: tagger/bitmap.h common/basics.h /usr/include/stdio.h
prob/represent.o: /usr/include/bits/libc-header-start.h
prob/represent.o: /usr/include/features.h /usr/include/features-time64.h
prob/represent.o: /usr/include/bits/wordsize.h /usr/include/bits/timesize.h
prob/represent.o: /usr/include/stdc-predef.h /usr/include/sys/cdefs.h
prob/represent.o: /usr/include/bits/long-double.h /usr/include/gnu/stubs.h
prob/represent.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
prob/represent.o: /usr/include/bits/time64.h
prob/represent.o: /usr/include/bits/types/__fpos_t.h
prob/represent.o: /usr/include/bits/types/__mbstate_t.h
prob/represent.o: /usr/include/bits/types/__fpos64_t.h
prob/represent.o: /usr/include/bits/types/__FILE.h
prob/represent.o: /usr/include/bits/types/FILE.h
prob/represent.o: /usr/include/bits/types/struct_FILE.h
prob/represent.o: /usr/include/bits/types/cookie_io_functions_t.h
prob/represent.o: /usr/include/bits/stdio_lim.h /usr/include/bits/floatn.h
prob/represent.o: /usr/include/bits/floatn-common.h common/ensure.h
prob/represent.o: /usr/include/assert.h common/file.h /usr/include/ctype.h
prob/represent.o: /usr/include/bits/endian.h /usr/include/bits/endianness.h
prob/represent.o: /usr/include/bits/types/locale_t.h
prob/represent.o: /usr/include/bits/types/__locale_t.h common/message.h
prob/represent.o: tagger/feature.h tagger/hasharray.h tagger/tag.h
prob/represent.o: /usr/include/string.h /usr/include/strings.h
prob/represent.o: tagger/hashscatter.h tagger/settings.h
prob/represent.o: /usr/include/limits.h /usr/include/bits/posix1_lim.h
prob/represent.o: /usr/include/bits/local_lim.h /usr/include/linux/limits.h
prob/represent.o: /usr/include/bits/pthread_stack_min-dynamic.h
prob/represent.o: /usr/include/bits/pthread_stack_min.h
prob/represent.o: /usr/include/bits/posix2_lim.h tagger/tagtrigram.h
prob/represent.o: tagger/token.h tagger/word.h tagger/inflectrule.h
prob/represent.o: tagger/wordtag.h common/stringbuf.h prob/annot.h
prob/represent.o: prob/config.h
prob/trigrams.o: prob/probadmin.h prob/prob.h prob/defines.h
prob/trigrams.o: tagger/tagdefines.h prob/probdefines.h
scrut/element.o: scrut/rules.h /usr/include/stdio.h
scrut/element.o: /usr/include/bits/libc-header-start.h
scrut/element.o: /usr/include/features.h /usr/include/features-time64.h
scrut/element.o: /usr/include/bits/wordsize.h /usr/include/bits/timesize.h
scrut/element.o: /usr/include/stdc-predef.h /usr/include/sys/cdefs.h
scrut/element.o: /usr/include/bits/long-double.h /usr/include/gnu/stubs.h
scrut/element.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
scrut/element.o: /usr/include/bits/time64.h
scrut/element.o: /usr/include/bits/types/__fpos_t.h
scrut/element.o: /usr/include/bits/types/__mbstate_t.h
scrut/element.o: /usr/include/bits/types/__fpos64_t.h
scrut/element.o: /usr/include/bits/types/__FILE.h
scrut/element.o: /usr/include/bits/types/FILE.h
scrut/element.o: /usr/include/bits/types/struct_FILE.h
scrut/element.o: /usr/include/bits/types/cookie_io_functions_t.h
scrut/element.o: /usr/include/bits/stdio_lim.h /usr/include/bits/floatn.h
scrut/element.o: /usr/include/bits/floatn-common.h common/stringbuf.h
scrut/element.o: /usr/include/string.h /usr/include/bits/types/locale_t.h
scrut/element.o: /usr/include/bits/types/__locale_t.h /usr/include/strings.h
scrut/element.o: common/basics.h common/ensure.h /usr/include/assert.h
scrut/element.o: tagger/text.h tagger/hashtable.h /usr/include/stdlib.h
scrut/element.o: /usr/include/sys/types.h /usr/include/bits/types/clock_t.h
scrut/element.o: /usr/include/bits/types/clockid_t.h
scrut/element.o: /usr/include/bits/types/time_t.h
scrut/element.o: /usr/include/bits/types/timer_t.h
scrut/element.o: /usr/include/bits/stdint-intn.h /usr/include/endian.h
scrut/element.o: /usr/include/bits/endian.h /usr/include/bits/endianness.h
scrut/element.o: /usr/include/bits/byteswap.h
scrut/element.o: /usr/include/bits/uintn-identity.h /usr/include/sys/select.h
scrut/element.o: /usr/include/bits/select.h
scrut/element.o: /usr/include/bits/types/sigset_t.h
scrut/element.o: /usr/include/bits/types/__sigset_t.h
scrut/element.o: /usr/include/bits/types/struct_timeval.h
scrut/element.o: /usr/include/bits/types/struct_timespec.h
scrut/element.o: /usr/include/bits/pthreadtypes.h
scrut/element.o: /usr/include/bits/thread-shared-types.h
scrut/element.o: /usr/include/bits/pthreadtypes-arch.h
scrut/element.o: /usr/include/bits/atomic_wide_counter.h
scrut/element.o: /usr/include/bits/struct_mutex.h
scrut/element.o: /usr/include/bits/struct_rwlock.h /usr/include/alloca.h
scrut/element.o: /usr/include/bits/stdlib-float.h scrut/evaluatedvariable.h
scrut/element.o: scrut/matching.h tagger/wordtoken.h tagger/letter.h
scrut/element.o: /usr/include/ctype.h tagger/settings.h /usr/include/limits.h
scrut/element.o: /usr/include/bits/posix1_lim.h /usr/include/bits/local_lim.h
scrut/element.o: /usr/include/linux/limits.h
scrut/element.o: /usr/include/bits/pthread_stack_min-dynamic.h
scrut/element.o: /usr/include/bits/pthread_stack_min.h
scrut/element.o: /usr/include/bits/posix2_lim.h tagger/token.h tagger/word.h
scrut/element.o: tagger/hashscatter.h tagger/inflectrule.h common/message.h
scrut/element.o: tagger/tag.h tagger/bitmap.h common/file.h tagger/feature.h
scrut/element.o: tagger/tagdefines.h tagger/wordtag.h scrut/element.h
scrut/element.o: scrut/rule.h common/timer.h /usr/include/sys/time.h
scrut/element.o: tagger/sentence.h tagger/taglexicon.h tagger/hasharray.h
scrut/element.o: tagger/tagtrigram.h scrut/semantictype.h scrut/operation.h
scrut/element.o: scrut/expr.h scrut/rulesettings.h scrut/ruleset.h
scrut/expr.o: scrut/expr.h scrut/evaluatedvariable.h scrut/matching.h
scrut/expr.o: tagger/wordtoken.h tagger/letter.h /usr/include/string.h
scrut/expr.o: /usr/include/bits/libc-header-start.h /usr/include/features.h
scrut/expr.o: /usr/include/features-time64.h /usr/include/bits/wordsize.h
scrut/expr.o: /usr/include/bits/timesize.h /usr/include/stdc-predef.h
scrut/expr.o: /usr/include/sys/cdefs.h /usr/include/bits/long-double.h
scrut/expr.o: /usr/include/gnu/stubs.h /usr/include/bits/types/locale_t.h
scrut/expr.o: /usr/include/bits/types/__locale_t.h /usr/include/strings.h
scrut/expr.o: /usr/include/ctype.h /usr/include/bits/types.h
scrut/expr.o: /usr/include/bits/typesizes.h /usr/include/bits/time64.h
scrut/expr.o: /usr/include/bits/endian.h /usr/include/bits/endianness.h
scrut/expr.o: common/basics.h /usr/include/stdio.h
scrut/expr.o: /usr/include/bits/types/__fpos_t.h
scrut/expr.o: /usr/include/bits/types/__mbstate_t.h
scrut/expr.o: /usr/include/bits/types/__fpos64_t.h
scrut/expr.o: /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h
scrut/expr.o: /usr/include/bits/types/struct_FILE.h
scrut/expr.o: /usr/include/bits/types/cookie_io_functions_t.h
scrut/expr.o: /usr/include/bits/stdio_lim.h /usr/include/bits/floatn.h
scrut/expr.o: /usr/include/bits/floatn-common.h common/ensure.h
scrut/expr.o: /usr/include/assert.h tagger/settings.h /usr/include/limits.h
scrut/expr.o: /usr/include/bits/posix1_lim.h /usr/include/bits/local_lim.h
scrut/expr.o: /usr/include/linux/limits.h
scrut/expr.o: /usr/include/bits/pthread_stack_min-dynamic.h
scrut/expr.o: /usr/include/bits/pthread_stack_min.h
scrut/expr.o: /usr/include/bits/posix2_lim.h common/stringbuf.h
scrut/expr.o: tagger/token.h tagger/word.h tagger/hashscatter.h
scrut/expr.o: tagger/inflectrule.h common/message.h tagger/tag.h
scrut/expr.o: tagger/bitmap.h common/file.h tagger/feature.h
scrut/expr.o: tagger/tagdefines.h tagger/wordtag.h scrut/element.h
scrut/expr.o: scrut/rule.h common/timer.h /usr/include/sys/time.h
scrut/expr.o: /usr/include/bits/types/time_t.h
scrut/expr.o: /usr/include/bits/types/struct_timeval.h
scrut/expr.o: /usr/include/sys/select.h /usr/include/bits/select.h
scrut/expr.o: /usr/include/bits/types/sigset_t.h
scrut/expr.o: /usr/include/bits/types/__sigset_t.h
scrut/expr.o: /usr/include/bits/types/struct_timespec.h tagger/sentence.h
scrut/expr.o: tagger/taglexicon.h tagger/hasharray.h tagger/tagtrigram.h
scrut/expr.o: scrut/operation.h scrut/rulesettings.h scrut/semantictype.h
scrut/expr.o: scrut/rules.h tagger/text.h tagger/hashtable.h
scrut/expr.o: /usr/include/stdlib.h /usr/include/sys/types.h
scrut/expr.o: /usr/include/bits/types/clock_t.h
scrut/expr.o: /usr/include/bits/types/clockid_t.h
scrut/expr.o: /usr/include/bits/types/timer_t.h
scrut/expr.o: /usr/include/bits/stdint-intn.h /usr/include/endian.h
scrut/expr.o: /usr/include/bits/byteswap.h /usr/include/bits/uintn-identity.h
scrut/expr.o: /usr/include/bits/pthreadtypes.h
scrut/expr.o: /usr/include/bits/thread-shared-types.h
scrut/expr.o: /usr/include/bits/pthreadtypes-arch.h
scrut/expr.o: /usr/include/bits/atomic_wide_counter.h
scrut/expr.o: /usr/include/bits/struct_mutex.h
scrut/expr.o: /usr/include/bits/struct_rwlock.h /usr/include/alloca.h
scrut/expr.o: /usr/include/bits/stdlib-float.h scrut/scrutinizer.h
scrut/expr.o: scrut/matchingset.h scrut/gramerror.h tagger/tagger.h
scrut/expr.o: tagger/lexicon.h tagger/morflexicon.h tagger/styleword.h
scrut/expr.o: tagger/newwordlexicon.h tagger/newword.h tagger/wordlexicon.h
scrut/expr.o: tagger/inflectlexicon.h tagger/wordruleterms.h
scrut/expr.o: token/tokenizer.h common/FlexLexer.h tagger/trigramgadget.h
scrut/expr.o: prob/memhandler.h
scrut/gramerror.o: scrut/expr.h scrut/evaluatedvariable.h scrut/matching.h
scrut/gramerror.o: tagger/wordtoken.h tagger/letter.h /usr/include/string.h
scrut/gramerror.o: /usr/include/bits/libc-header-start.h
scrut/gramerror.o: /usr/include/features.h /usr/include/features-time64.h
scrut/gramerror.o: /usr/include/bits/wordsize.h /usr/include/bits/timesize.h
scrut/gramerror.o: /usr/include/stdc-predef.h /usr/include/sys/cdefs.h
scrut/gramerror.o: /usr/include/bits/long-double.h /usr/include/gnu/stubs.h
scrut/gramerror.o: /usr/include/bits/types/locale_t.h
scrut/gramerror.o: /usr/include/bits/types/__locale_t.h
scrut/gramerror.o: /usr/include/strings.h /usr/include/ctype.h
scrut/gramerror.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
scrut/gramerror.o: /usr/include/bits/time64.h /usr/include/bits/endian.h
scrut/gramerror.o: /usr/include/bits/endianness.h common/basics.h
scrut/gramerror.o: /usr/include/stdio.h /usr/include/bits/types/__fpos_t.h
scrut/gramerror.o: /usr/include/bits/types/__mbstate_t.h
scrut/gramerror.o: /usr/include/bits/types/__fpos64_t.h
scrut/gramerror.o: /usr/include/bits/types/__FILE.h
scrut/gramerror.o: /usr/include/bits/types/FILE.h
scrut/gramerror.o: /usr/include/bits/types/struct_FILE.h
scrut/gramerror.o: /usr/include/bits/types/cookie_io_functions_t.h
scrut/gramerror.o: /usr/include/bits/stdio_lim.h /usr/include/bits/floatn.h
scrut/gramerror.o: /usr/include/bits/floatn-common.h common/ensure.h
scrut/gramerror.o: /usr/include/assert.h tagger/settings.h
scrut/gramerror.o: /usr/include/limits.h /usr/include/bits/posix1_lim.h
scrut/gramerror.o: /usr/include/bits/local_lim.h /usr/include/linux/limits.h
scrut/gramerror.o: /usr/include/bits/pthread_stack_min-dynamic.h
scrut/gramerror.o: /usr/include/bits/pthread_stack_min.h
scrut/gramerror.o: /usr/include/bits/posix2_lim.h common/stringbuf.h
scrut/gramerror.o: tagger/token.h tagger/word.h tagger/hashscatter.h
scrut/gramerror.o: tagger/inflectrule.h common/message.h tagger/tag.h
scrut/gramerror.o: tagger/bitmap.h common/file.h tagger/feature.h
scrut/gramerror.o: tagger/tagdefines.h tagger/wordtag.h scrut/element.h
scrut/gramerror.o: scrut/rule.h common/timer.h /usr/include/sys/time.h
scrut/gramerror.o: /usr/include/bits/types/time_t.h
scrut/gramerror.o: /usr/include/bits/types/struct_timeval.h
scrut/gramerror.o: /usr/include/sys/select.h /usr/include/bits/select.h
scrut/gramerror.o: /usr/include/bits/types/sigset_t.h
scrut/gramerror.o: /usr/include/bits/types/__sigset_t.h
scrut/gramerror.o: /usr/include/bits/types/struct_timespec.h
scrut/gramerror.o: tagger/sentence.h tagger/taglexicon.h tagger/hasharray.h
scrut/gramerror.o: tagger/tagtrigram.h scrut/operation.h scrut/rulesettings.h
scrut/gramerror.o: scrut/semantictype.h scrut/gramerror.h scrut/scrutinizer.h
scrut/gramerror.o: scrut/matchingset.h scrut/rules.h tagger/text.h
scrut/gramerror.o: tagger/hashtable.h /usr/include/stdlib.h
scrut/gramerror.o: /usr/include/sys/types.h /usr/include/bits/types/clock_t.h
scrut/gramerror.o: /usr/include/bits/types/clockid_t.h
scrut/gramerror.o: /usr/include/bits/types/timer_t.h
scrut/gramerror.o: /usr/include/bits/stdint-intn.h /usr/include/endian.h
scrut/gramerror.o: /usr/include/bits/byteswap.h
scrut/gramerror.o: /usr/include/bits/uintn-identity.h
scrut/gramerror.o: /usr/include/bits/pthreadtypes.h
scrut/gramerror.o: /usr/include/bits/thread-shared-types.h
scrut/gramerror.o: /usr/include/bits/pthreadtypes-arch.h
scrut/gramerror.o: /usr/include/bits/atomic_wide_counter.h
scrut/gramerror.o: /usr/include/bits/struct_mutex.h
scrut/gramerror.o: /usr/include/bits/struct_rwlock.h /usr/include/alloca.h
scrut/gramerror.o: /usr/include/bits/stdlib-float.h tagger/tagger.h
scrut/gramerror.o: tagger/lexicon.h tagger/morflexicon.h tagger/styleword.h
scrut/gramerror.o: tagger/newwordlexicon.h tagger/newword.h
scrut/gramerror.o: tagger/wordlexicon.h tagger/inflectlexicon.h
scrut/gramerror.o: tagger/wordruleterms.h token/tokenizer.h
scrut/gramerror.o: common/FlexLexer.h tagger/trigramgadget.h prob/prob.h
scrut/gramerror.o: prob/output.h ../misc/xmloutput.h
scrut/identry.o: scrut/rules.h /usr/include/stdio.h
scrut/identry.o: /usr/include/bits/libc-header-start.h
scrut/identry.o: /usr/include/features.h /usr/include/features-time64.h
scrut/identry.o: /usr/include/bits/wordsize.h /usr/include/bits/timesize.h
scrut/identry.o: /usr/include/stdc-predef.h /usr/include/sys/cdefs.h
scrut/identry.o: /usr/include/bits/long-double.h /usr/include/gnu/stubs.h
scrut/identry.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
scrut/identry.o: /usr/include/bits/time64.h
scrut/identry.o: /usr/include/bits/types/__fpos_t.h
scrut/identry.o: /usr/include/bits/types/__mbstate_t.h
scrut/identry.o: /usr/include/bits/types/__fpos64_t.h
scrut/identry.o: /usr/include/bits/types/__FILE.h
scrut/identry.o: /usr/include/bits/types/FILE.h
scrut/identry.o: /usr/include/bits/types/struct_FILE.h
scrut/identry.o: /usr/include/bits/types/cookie_io_functions_t.h
scrut/identry.o: /usr/include/bits/stdio_lim.h /usr/include/bits/floatn.h
scrut/identry.o: /usr/include/bits/floatn-common.h common/stringbuf.h
scrut/identry.o: /usr/include/string.h /usr/include/bits/types/locale_t.h
scrut/identry.o: /usr/include/bits/types/__locale_t.h /usr/include/strings.h
scrut/identry.o: common/basics.h common/ensure.h /usr/include/assert.h
scrut/identry.o: tagger/text.h tagger/hashtable.h /usr/include/stdlib.h
scrut/identry.o: /usr/include/sys/types.h /usr/include/bits/types/clock_t.h
scrut/identry.o: /usr/include/bits/types/clockid_t.h
scrut/identry.o: /usr/include/bits/types/time_t.h
scrut/identry.o: /usr/include/bits/types/timer_t.h
scrut/identry.o: /usr/include/bits/stdint-intn.h /usr/include/endian.h
scrut/identry.o: /usr/include/bits/endian.h /usr/include/bits/endianness.h
scrut/identry.o: /usr/include/bits/byteswap.h
scrut/identry.o: /usr/include/bits/uintn-identity.h /usr/include/sys/select.h
scrut/identry.o: /usr/include/bits/select.h
scrut/identry.o: /usr/include/bits/types/sigset_t.h
scrut/identry.o: /usr/include/bits/types/__sigset_t.h
scrut/identry.o: /usr/include/bits/types/struct_timeval.h
scrut/identry.o: /usr/include/bits/types/struct_timespec.h
scrut/identry.o: /usr/include/bits/pthreadtypes.h
scrut/identry.o: /usr/include/bits/thread-shared-types.h
scrut/identry.o: /usr/include/bits/pthreadtypes-arch.h
scrut/identry.o: /usr/include/bits/atomic_wide_counter.h
scrut/identry.o: /usr/include/bits/struct_mutex.h
scrut/identry.o: /usr/include/bits/struct_rwlock.h /usr/include/alloca.h
scrut/identry.o: /usr/include/bits/stdlib-float.h scrut/evaluatedvariable.h
scrut/identry.o: scrut/matching.h tagger/wordtoken.h tagger/letter.h
scrut/identry.o: /usr/include/ctype.h tagger/settings.h /usr/include/limits.h
scrut/identry.o: /usr/include/bits/posix1_lim.h /usr/include/bits/local_lim.h
scrut/identry.o: /usr/include/linux/limits.h
scrut/identry.o: /usr/include/bits/pthread_stack_min-dynamic.h
scrut/identry.o: /usr/include/bits/pthread_stack_min.h
scrut/identry.o: /usr/include/bits/posix2_lim.h tagger/token.h tagger/word.h
scrut/identry.o: tagger/hashscatter.h tagger/inflectrule.h common/message.h
scrut/identry.o: tagger/tag.h tagger/bitmap.h common/file.h tagger/feature.h
scrut/identry.o: tagger/tagdefines.h tagger/wordtag.h scrut/element.h
scrut/identry.o: scrut/rule.h common/timer.h /usr/include/sys/time.h
scrut/identry.o: tagger/sentence.h tagger/taglexicon.h tagger/hasharray.h
scrut/identry.o: tagger/tagtrigram.h scrut/semantictype.h scrut/operation.h
scrut/identry.o: scrut/expr.h scrut/rulesettings.h prob/memhandler.h
scrut/matching.o: scrut/rule.h common/timer.h /usr/include/sys/time.h
scrut/matching.o: /usr/include/features.h /usr/include/features-time64.h
scrut/matching.o: /usr/include/bits/wordsize.h /usr/include/bits/timesize.h
scrut/matching.o: /usr/include/stdc-predef.h /usr/include/sys/cdefs.h
scrut/matching.o: /usr/include/bits/long-double.h /usr/include/gnu/stubs.h
scrut/matching.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
scrut/matching.o: /usr/include/bits/time64.h /usr/include/bits/types/time_t.h
scrut/matching.o: /usr/include/bits/types/struct_timeval.h
scrut/matching.o: /usr/include/sys/select.h /usr/include/bits/select.h
scrut/matching.o: /usr/include/bits/types/sigset_t.h
scrut/matching.o: /usr/include/bits/types/__sigset_t.h
scrut/matching.o: /usr/include/bits/types/struct_timespec.h
scrut/matching.o: /usr/include/bits/endian.h /usr/include/bits/endianness.h
scrut/matching.o: tagger/sentence.h tagger/wordtoken.h tagger/letter.h
scrut/matching.o: /usr/include/string.h /usr/include/bits/libc-header-start.h
scrut/matching.o: /usr/include/bits/types/locale_t.h
scrut/matching.o: /usr/include/bits/types/__locale_t.h /usr/include/strings.h
scrut/matching.o: /usr/include/ctype.h common/basics.h /usr/include/stdio.h
scrut/matching.o: /usr/include/bits/types/__fpos_t.h
scrut/matching.o: /usr/include/bits/types/__mbstate_t.h
scrut/matching.o: /usr/include/bits/types/__fpos64_t.h
scrut/matching.o: /usr/include/bits/types/__FILE.h
scrut/matching.o: /usr/include/bits/types/FILE.h
scrut/matching.o: /usr/include/bits/types/struct_FILE.h
scrut/matching.o: /usr/include/bits/types/cookie_io_functions_t.h
scrut/matching.o: /usr/include/bits/stdio_lim.h /usr/include/bits/floatn.h
scrut/matching.o: /usr/include/bits/floatn-common.h common/ensure.h
scrut/matching.o: /usr/include/assert.h tagger/settings.h
scrut/matching.o: /usr/include/limits.h /usr/include/bits/posix1_lim.h
scrut/matching.o: /usr/include/bits/local_lim.h /usr/include/linux/limits.h
scrut/matching.o: /usr/include/bits/pthread_stack_min-dynamic.h
scrut/matching.o: /usr/include/bits/pthread_stack_min.h
scrut/matching.o: /usr/include/bits/posix2_lim.h common/stringbuf.h
scrut/matching.o: tagger/token.h tagger/word.h tagger/hashscatter.h
scrut/matching.o: tagger/inflectrule.h common/message.h tagger/tag.h
scrut/matching.o: tagger/bitmap.h common/file.h tagger/feature.h
scrut/matching.o: tagger/tagdefines.h tagger/wordtag.h scrut/element.h
scrut/matching.o: tagger/taglexicon.h tagger/hasharray.h tagger/tagtrigram.h
scrut/matching.o: scrut/rules.h tagger/text.h tagger/hashtable.h
scrut/matching.o: /usr/include/stdlib.h /usr/include/sys/types.h
scrut/matching.o: /usr/include/bits/types/clock_t.h
scrut/matching.o: /usr/include/bits/types/clockid_t.h
scrut/matching.o: /usr/include/bits/types/timer_t.h
scrut/matching.o: /usr/include/bits/stdint-intn.h /usr/include/endian.h
scrut/matching.o: /usr/include/bits/byteswap.h
scrut/matching.o: /usr/include/bits/uintn-identity.h
scrut/matching.o: /usr/include/bits/pthreadtypes.h
scrut/matching.o: /usr/include/bits/thread-shared-types.h
scrut/matching.o: /usr/include/bits/pthreadtypes-arch.h
scrut/matching.o: /usr/include/bits/atomic_wide_counter.h
scrut/matching.o: /usr/include/bits/struct_mutex.h
scrut/matching.o: /usr/include/bits/struct_rwlock.h /usr/include/alloca.h
scrut/matching.o: /usr/include/bits/stdlib-float.h scrut/evaluatedvariable.h
scrut/matching.o: scrut/matching.h scrut/semantictype.h scrut/operation.h
scrut/matching.o: scrut/expr.h scrut/rulesettings.h
scrut/matchingset.o: scrut/matchingset.h scrut/matching.h tagger/wordtoken.h
scrut/matchingset.o: tagger/letter.h /usr/include/string.h
scrut/matchingset.o: /usr/include/bits/libc-header-start.h
scrut/matchingset.o: /usr/include/features.h /usr/include/features-time64.h
scrut/matchingset.o: /usr/include/bits/wordsize.h
scrut/matchingset.o: /usr/include/bits/timesize.h /usr/include/stdc-predef.h
scrut/matchingset.o: /usr/include/sys/cdefs.h /usr/include/bits/long-double.h
scrut/matchingset.o: /usr/include/gnu/stubs.h
scrut/matchingset.o: /usr/include/bits/types/locale_t.h
scrut/matchingset.o: /usr/include/bits/types/__locale_t.h
scrut/matchingset.o: /usr/include/strings.h /usr/include/ctype.h
scrut/matchingset.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
scrut/matchingset.o: /usr/include/bits/time64.h /usr/include/bits/endian.h
scrut/matchingset.o: /usr/include/bits/endianness.h common/basics.h
scrut/matchingset.o: /usr/include/stdio.h /usr/include/bits/types/__fpos_t.h
scrut/matchingset.o: /usr/include/bits/types/__mbstate_t.h
scrut/matchingset.o: /usr/include/bits/types/__fpos64_t.h
scrut/matchingset.o: /usr/include/bits/types/__FILE.h
scrut/matchingset.o: /usr/include/bits/types/FILE.h
scrut/matchingset.o: /usr/include/bits/types/struct_FILE.h
scrut/matchingset.o: /usr/include/bits/types/cookie_io_functions_t.h
scrut/matchingset.o: /usr/include/bits/stdio_lim.h /usr/include/bits/floatn.h
scrut/matchingset.o: /usr/include/bits/floatn-common.h common/ensure.h
scrut/matchingset.o: /usr/include/assert.h tagger/settings.h
scrut/matchingset.o: /usr/include/limits.h /usr/include/bits/posix1_lim.h
scrut/matchingset.o: /usr/include/bits/local_lim.h
scrut/matchingset.o: /usr/include/linux/limits.h
scrut/matchingset.o: /usr/include/bits/pthread_stack_min-dynamic.h
scrut/matchingset.o: /usr/include/bits/pthread_stack_min.h
scrut/matchingset.o: /usr/include/bits/posix2_lim.h common/stringbuf.h
scrut/matchingset.o: tagger/token.h tagger/word.h tagger/hashscatter.h
scrut/matchingset.o: tagger/inflectrule.h common/message.h tagger/tag.h
scrut/matchingset.o: tagger/bitmap.h common/file.h tagger/feature.h
scrut/matchingset.o: tagger/tagdefines.h tagger/wordtag.h scrut/element.h
scrut/matchingset.o: scrut/rule.h common/timer.h /usr/include/sys/time.h
scrut/matchingset.o: /usr/include/bits/types/time_t.h
scrut/matchingset.o: /usr/include/bits/types/struct_timeval.h
scrut/matchingset.o: /usr/include/sys/select.h /usr/include/bits/select.h
scrut/matchingset.o: /usr/include/bits/types/sigset_t.h
scrut/matchingset.o: /usr/include/bits/types/__sigset_t.h
scrut/matchingset.o: /usr/include/bits/types/struct_timespec.h
scrut/matchingset.o: tagger/sentence.h tagger/taglexicon.h tagger/hasharray.h
scrut/matchingset.o: tagger/tagtrigram.h scrut/gramerror.h
scrut/matchingset.o: scrut/rulesettings.h
scrut/operation.o: scrut/expr.h scrut/evaluatedvariable.h scrut/matching.h
scrut/operation.o: tagger/wordtoken.h tagger/letter.h /usr/include/string.h
scrut/operation.o: /usr/include/bits/libc-header-start.h
scrut/operation.o: /usr/include/features.h /usr/include/features-time64.h
scrut/operation.o: /usr/include/bits/wordsize.h /usr/include/bits/timesize.h
scrut/operation.o: /usr/include/stdc-predef.h /usr/include/sys/cdefs.h
scrut/operation.o: /usr/include/bits/long-double.h /usr/include/gnu/stubs.h
scrut/operation.o: /usr/include/bits/types/locale_t.h
scrut/operation.o: /usr/include/bits/types/__locale_t.h
scrut/operation.o: /usr/include/strings.h /usr/include/ctype.h
scrut/operation.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
scrut/operation.o: /usr/include/bits/time64.h /usr/include/bits/endian.h
scrut/operation.o: /usr/include/bits/endianness.h common/basics.h
scrut/operation.o: /usr/include/stdio.h /usr/include/bits/types/__fpos_t.h
scrut/operation.o: /usr/include/bits/types/__mbstate_t.h
scrut/operation.o: /usr/include/bits/types/__fpos64_t.h
scrut/operation.o: /usr/include/bits/types/__FILE.h
scrut/operation.o: /usr/include/bits/types/FILE.h
scrut/operation.o: /usr/include/bits/types/struct_FILE.h
scrut/operation.o: /usr/include/bits/types/cookie_io_functions_t.h
scrut/operation.o: /usr/include/bits/stdio_lim.h /usr/include/bits/floatn.h
scrut/operation.o: /usr/include/bits/floatn-common.h common/ensure.h
scrut/operation.o: /usr/include/assert.h tagger/settings.h
scrut/operation.o: /usr/include/limits.h /usr/include/bits/posix1_lim.h
scrut/operation.o: /usr/include/bits/local_lim.h /usr/include/linux/limits.h
scrut/operation.o: /usr/include/bits/pthread_stack_min-dynamic.h
scrut/operation.o: /usr/include/bits/pthread_stack_min.h
scrut/operation.o: /usr/include/bits/posix2_lim.h common/stringbuf.h
scrut/operation.o: tagger/token.h tagger/word.h tagger/hashscatter.h
scrut/operation.o: tagger/inflectrule.h common/message.h tagger/tag.h
scrut/operation.o: tagger/bitmap.h common/file.h tagger/feature.h
scrut/operation.o: tagger/tagdefines.h tagger/wordtag.h scrut/element.h
scrut/operation.o: scrut/rule.h common/timer.h /usr/include/sys/time.h
scrut/operation.o: /usr/include/bits/types/time_t.h
scrut/operation.o: /usr/include/bits/types/struct_timeval.h
scrut/operation.o: /usr/include/sys/select.h /usr/include/bits/select.h
scrut/operation.o: /usr/include/bits/types/sigset_t.h
scrut/operation.o: /usr/include/bits/types/__sigset_t.h
scrut/operation.o: /usr/include/bits/types/struct_timespec.h
scrut/operation.o: tagger/sentence.h tagger/taglexicon.h tagger/hasharray.h
scrut/operation.o: tagger/tagtrigram.h scrut/operation.h scrut/rulesettings.h
scrut/operation.o: scrut/semantictype.h
scrut/regexps.o: /usr/include/stdlib.h /usr/include/bits/libc-header-start.h
scrut/regexps.o: /usr/include/features.h /usr/include/features-time64.h
scrut/regexps.o: /usr/include/bits/wordsize.h /usr/include/bits/timesize.h
scrut/regexps.o: /usr/include/stdc-predef.h /usr/include/sys/cdefs.h
scrut/regexps.o: /usr/include/bits/long-double.h /usr/include/gnu/stubs.h
scrut/regexps.o: /usr/include/bits/floatn.h /usr/include/bits/floatn-common.h
scrut/regexps.o: /usr/include/sys/types.h /usr/include/bits/types.h
scrut/regexps.o: /usr/include/bits/typesizes.h /usr/include/bits/time64.h
scrut/regexps.o: /usr/include/bits/types/clock_t.h
scrut/regexps.o: /usr/include/bits/types/clockid_t.h
scrut/regexps.o: /usr/include/bits/types/time_t.h
scrut/regexps.o: /usr/include/bits/types/timer_t.h
scrut/regexps.o: /usr/include/bits/stdint-intn.h /usr/include/endian.h
scrut/regexps.o: /usr/include/bits/endian.h /usr/include/bits/endianness.h
scrut/regexps.o: /usr/include/bits/byteswap.h
scrut/regexps.o: /usr/include/bits/uintn-identity.h /usr/include/sys/select.h
scrut/regexps.o: /usr/include/bits/select.h
scrut/regexps.o: /usr/include/bits/types/sigset_t.h
scrut/regexps.o: /usr/include/bits/types/__sigset_t.h
scrut/regexps.o: /usr/include/bits/types/struct_timeval.h
scrut/regexps.o: /usr/include/bits/types/struct_timespec.h
scrut/regexps.o: /usr/include/bits/pthreadtypes.h
scrut/regexps.o: /usr/include/bits/thread-shared-types.h
scrut/regexps.o: /usr/include/bits/pthreadtypes-arch.h
scrut/regexps.o: /usr/include/bits/atomic_wide_counter.h
scrut/regexps.o: /usr/include/bits/struct_mutex.h
scrut/regexps.o: /usr/include/bits/struct_rwlock.h /usr/include/alloca.h
scrut/regexps.o: /usr/include/bits/stdlib-float.h /usr/include/stdio.h
scrut/regexps.o: /usr/include/bits/types/__fpos_t.h
scrut/regexps.o: /usr/include/bits/types/__mbstate_t.h
scrut/regexps.o: /usr/include/bits/types/__fpos64_t.h
scrut/regexps.o: /usr/include/bits/types/__FILE.h
scrut/regexps.o: /usr/include/bits/types/FILE.h
scrut/regexps.o: /usr/include/bits/types/struct_FILE.h
scrut/regexps.o: /usr/include/bits/types/cookie_io_functions_t.h
scrut/regexps.o: /usr/include/bits/stdio_lim.h /usr/include/string.h
scrut/regexps.o: /usr/include/bits/types/locale_t.h
scrut/regexps.o: /usr/include/bits/types/__locale_t.h /usr/include/strings.h
scrut/regexps.o: scrut/regexp.h
scrut/rule.o: scrut/scrutinizer.h scrut/matching.h tagger/wordtoken.h
scrut/rule.o: tagger/letter.h /usr/include/string.h
scrut/rule.o: /usr/include/bits/libc-header-start.h /usr/include/features.h
scrut/rule.o: /usr/include/features-time64.h /usr/include/bits/wordsize.h
scrut/rule.o: /usr/include/bits/timesize.h /usr/include/stdc-predef.h
scrut/rule.o: /usr/include/sys/cdefs.h /usr/include/bits/long-double.h
scrut/rule.o: /usr/include/gnu/stubs.h /usr/include/bits/types/locale_t.h
scrut/rule.o: /usr/include/bits/types/__locale_t.h /usr/include/strings.h
scrut/rule.o: /usr/include/ctype.h /usr/include/bits/types.h
scrut/rule.o: /usr/include/bits/typesizes.h /usr/include/bits/time64.h
scrut/rule.o: /usr/include/bits/endian.h /usr/include/bits/endianness.h
scrut/rule.o: common/basics.h /usr/include/stdio.h
scrut/rule.o: /usr/include/bits/types/__fpos_t.h
scrut/rule.o: /usr/include/bits/types/__mbstate_t.h
scrut/rule.o: /usr/include/bits/types/__fpos64_t.h
scrut/rule.o: /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h
scrut/rule.o: /usr/include/bits/types/struct_FILE.h
scrut/rule.o: /usr/include/bits/types/cookie_io_functions_t.h
scrut/rule.o: /usr/include/bits/stdio_lim.h /usr/include/bits/floatn.h
scrut/rule.o: /usr/include/bits/floatn-common.h common/ensure.h
scrut/rule.o: /usr/include/assert.h tagger/settings.h /usr/include/limits.h
scrut/rule.o: /usr/include/bits/posix1_lim.h /usr/include/bits/local_lim.h
scrut/rule.o: /usr/include/linux/limits.h
scrut/rule.o: /usr/include/bits/pthread_stack_min-dynamic.h
scrut/rule.o: /usr/include/bits/pthread_stack_min.h
scrut/rule.o: /usr/include/bits/posix2_lim.h common/stringbuf.h
scrut/rule.o: tagger/token.h tagger/word.h tagger/hashscatter.h
scrut/rule.o: tagger/inflectrule.h common/message.h tagger/tag.h
scrut/rule.o: tagger/bitmap.h common/file.h tagger/feature.h
scrut/rule.o: tagger/tagdefines.h tagger/wordtag.h scrut/element.h
scrut/rule.o: scrut/rule.h common/timer.h /usr/include/sys/time.h
scrut/rule.o: /usr/include/bits/types/time_t.h
scrut/rule.o: /usr/include/bits/types/struct_timeval.h
scrut/rule.o: /usr/include/sys/select.h /usr/include/bits/select.h
scrut/rule.o: /usr/include/bits/types/sigset_t.h
scrut/rule.o: /usr/include/bits/types/__sigset_t.h
scrut/rule.o: /usr/include/bits/types/struct_timespec.h tagger/sentence.h
scrut/rule.o: tagger/taglexicon.h tagger/hasharray.h tagger/tagtrigram.h
scrut/rule.o: scrut/matchingset.h scrut/rules.h tagger/text.h
scrut/rule.o: tagger/hashtable.h /usr/include/stdlib.h
scrut/rule.o: /usr/include/sys/types.h /usr/include/bits/types/clock_t.h
scrut/rule.o: /usr/include/bits/types/clockid_t.h
scrut/rule.o: /usr/include/bits/types/timer_t.h
scrut/rule.o: /usr/include/bits/stdint-intn.h /usr/include/endian.h
scrut/rule.o: /usr/include/bits/byteswap.h /usr/include/bits/uintn-identity.h
scrut/rule.o: /usr/include/bits/pthreadtypes.h
scrut/rule.o: /usr/include/bits/thread-shared-types.h
scrut/rule.o: /usr/include/bits/pthreadtypes-arch.h
scrut/rule.o: /usr/include/bits/atomic_wide_counter.h
scrut/rule.o: /usr/include/bits/struct_mutex.h
scrut/rule.o: /usr/include/bits/struct_rwlock.h /usr/include/alloca.h
scrut/rule.o: /usr/include/bits/stdlib-float.h scrut/evaluatedvariable.h
scrut/rule.o: scrut/semantictype.h scrut/operation.h scrut/expr.h
scrut/rule.o: scrut/rulesettings.h scrut/gramerror.h tagger/tagger.h
scrut/rule.o: tagger/lexicon.h tagger/morflexicon.h tagger/styleword.h
scrut/rule.o: tagger/newwordlexicon.h tagger/newword.h tagger/wordlexicon.h
scrut/rule.o: tagger/inflectlexicon.h tagger/wordruleterms.h
scrut/rule.o: token/tokenizer.h common/FlexLexer.h tagger/trigramgadget.h
scrut/rule.o: scrut/ruleset.h
scrut/ruleset.o: scrut/rules.h /usr/include/stdio.h
scrut/ruleset.o: /usr/include/bits/libc-header-start.h
scrut/ruleset.o: /usr/include/features.h /usr/include/features-time64.h
scrut/ruleset.o: /usr/include/bits/wordsize.h /usr/include/bits/timesize.h
scrut/ruleset.o: /usr/include/stdc-predef.h /usr/include/sys/cdefs.h
scrut/ruleset.o: /usr/include/bits/long-double.h /usr/include/gnu/stubs.h
scrut/ruleset.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
scrut/ruleset.o: /usr/include/bits/time64.h
scrut/ruleset.o: /usr/include/bits/types/__fpos_t.h
scrut/ruleset.o: /usr/include/bits/types/__mbstate_t.h
scrut/ruleset.o: /usr/include/bits/types/__fpos64_t.h
scrut/ruleset.o: /usr/include/bits/types/__FILE.h
scrut/ruleset.o: /usr/include/bits/types/FILE.h
scrut/ruleset.o: /usr/include/bits/types/struct_FILE.h
scrut/ruleset.o: /usr/include/bits/types/cookie_io_functions_t.h
scrut/ruleset.o: /usr/include/bits/stdio_lim.h /usr/include/bits/floatn.h
scrut/ruleset.o: /usr/include/bits/floatn-common.h common/stringbuf.h
scrut/ruleset.o: /usr/include/string.h /usr/include/bits/types/locale_t.h
scrut/ruleset.o: /usr/include/bits/types/__locale_t.h /usr/include/strings.h
scrut/ruleset.o: common/basics.h common/ensure.h /usr/include/assert.h
scrut/ruleset.o: tagger/text.h tagger/hashtable.h /usr/include/stdlib.h
scrut/ruleset.o: /usr/include/sys/types.h /usr/include/bits/types/clock_t.h
scrut/ruleset.o: /usr/include/bits/types/clockid_t.h
scrut/ruleset.o: /usr/include/bits/types/time_t.h
scrut/ruleset.o: /usr/include/bits/types/timer_t.h
scrut/ruleset.o: /usr/include/bits/stdint-intn.h /usr/include/endian.h
scrut/ruleset.o: /usr/include/bits/endian.h /usr/include/bits/endianness.h
scrut/ruleset.o: /usr/include/bits/byteswap.h
scrut/ruleset.o: /usr/include/bits/uintn-identity.h /usr/include/sys/select.h
scrut/ruleset.o: /usr/include/bits/select.h
scrut/ruleset.o: /usr/include/bits/types/sigset_t.h
scrut/ruleset.o: /usr/include/bits/types/__sigset_t.h
scrut/ruleset.o: /usr/include/bits/types/struct_timeval.h
scrut/ruleset.o: /usr/include/bits/types/struct_timespec.h
scrut/ruleset.o: /usr/include/bits/pthreadtypes.h
scrut/ruleset.o: /usr/include/bits/thread-shared-types.h
scrut/ruleset.o: /usr/include/bits/pthreadtypes-arch.h
scrut/ruleset.o: /usr/include/bits/atomic_wide_counter.h
scrut/ruleset.o: /usr/include/bits/struct_mutex.h
scrut/ruleset.o: /usr/include/bits/struct_rwlock.h /usr/include/alloca.h
scrut/ruleset.o: /usr/include/bits/stdlib-float.h scrut/evaluatedvariable.h
scrut/ruleset.o: scrut/matching.h tagger/wordtoken.h tagger/letter.h
scrut/ruleset.o: /usr/include/ctype.h tagger/settings.h /usr/include/limits.h
scrut/ruleset.o: /usr/include/bits/posix1_lim.h /usr/include/bits/local_lim.h
scrut/ruleset.o: /usr/include/linux/limits.h
scrut/ruleset.o: /usr/include/bits/pthread_stack_min-dynamic.h
scrut/ruleset.o: /usr/include/bits/pthread_stack_min.h
scrut/ruleset.o: /usr/include/bits/posix2_lim.h tagger/token.h tagger/word.h
scrut/ruleset.o: tagger/hashscatter.h tagger/inflectrule.h common/message.h
scrut/ruleset.o: tagger/tag.h tagger/bitmap.h common/file.h tagger/feature.h
scrut/ruleset.o: tagger/tagdefines.h tagger/wordtag.h scrut/element.h
scrut/ruleset.o: scrut/rule.h common/timer.h /usr/include/sys/time.h
scrut/ruleset.o: tagger/sentence.h tagger/taglexicon.h tagger/hasharray.h
scrut/ruleset.o: tagger/tagtrigram.h scrut/semantictype.h scrut/operation.h
scrut/ruleset.o: scrut/expr.h scrut/rulesettings.h scrut/ruleset.h
scrut/rulesettings.o: scrut/rulesettings.h common/basics.h
scrut/rulesettings.o: /usr/include/stdio.h
scrut/rulesettings.o: /usr/include/bits/libc-header-start.h
scrut/rulesettings.o: /usr/include/features.h /usr/include/features-time64.h
scrut/rulesettings.o: /usr/include/bits/wordsize.h
scrut/rulesettings.o: /usr/include/bits/timesize.h /usr/include/stdc-predef.h
scrut/rulesettings.o: /usr/include/sys/cdefs.h
scrut/rulesettings.o: /usr/include/bits/long-double.h
scrut/rulesettings.o: /usr/include/gnu/stubs.h /usr/include/bits/types.h
scrut/rulesettings.o: /usr/include/bits/typesizes.h
scrut/rulesettings.o: /usr/include/bits/time64.h
scrut/rulesettings.o: /usr/include/bits/types/__fpos_t.h
scrut/rulesettings.o: /usr/include/bits/types/__mbstate_t.h
scrut/rulesettings.o: /usr/include/bits/types/__fpos64_t.h
scrut/rulesettings.o: /usr/include/bits/types/__FILE.h
scrut/rulesettings.o: /usr/include/bits/types/FILE.h
scrut/rulesettings.o: /usr/include/bits/types/struct_FILE.h
scrut/rulesettings.o: /usr/include/bits/types/cookie_io_functions_t.h
scrut/rulesettings.o: /usr/include/bits/stdio_lim.h
scrut/rulesettings.o: /usr/include/bits/floatn.h
scrut/rulesettings.o: /usr/include/bits/floatn-common.h common/ensure.h
scrut/rulesettings.o: /usr/include/assert.h
scrut/scrutinizer.o: scrut/scrutinizer.h scrut/matching.h tagger/wordtoken.h
scrut/scrutinizer.o: tagger/letter.h /usr/include/string.h
scrut/scrutinizer.o: /usr/include/bits/libc-header-start.h
scrut/scrutinizer.o: /usr/include/features.h /usr/include/features-time64.h
scrut/scrutinizer.o: /usr/include/bits/wordsize.h
scrut/scrutinizer.o: /usr/include/bits/timesize.h /usr/include/stdc-predef.h
scrut/scrutinizer.o: /usr/include/sys/cdefs.h /usr/include/bits/long-double.h
scrut/scrutinizer.o: /usr/include/gnu/stubs.h
scrut/scrutinizer.o: /usr/include/bits/types/locale_t.h
scrut/scrutinizer.o: /usr/include/bits/types/__locale_t.h
scrut/scrutinizer.o: /usr/include/strings.h /usr/include/ctype.h
scrut/scrutinizer.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
scrut/scrutinizer.o: /usr/include/bits/time64.h /usr/include/bits/endian.h
scrut/scrutinizer.o: /usr/include/bits/endianness.h common/basics.h
scrut/scrutinizer.o: /usr/include/stdio.h /usr/include/bits/types/__fpos_t.h
scrut/scrutinizer.o: /usr/include/bits/types/__mbstate_t.h
scrut/scrutinizer.o: /usr/include/bits/types/__fpos64_t.h
scrut/scrutinizer.o: /usr/include/bits/types/__FILE.h
scrut/scrutinizer.o: /usr/include/bits/types/FILE.h
scrut/scrutinizer.o: /usr/include/bits/types/struct_FILE.h
scrut/scrutinizer.o: /usr/include/bits/types/cookie_io_functions_t.h
scrut/scrutinizer.o: /usr/include/bits/stdio_lim.h /usr/include/bits/floatn.h
scrut/scrutinizer.o: /usr/include/bits/floatn-common.h common/ensure.h
scrut/scrutinizer.o: /usr/include/assert.h tagger/settings.h
scrut/scrutinizer.o: /usr/include/limits.h /usr/include/bits/posix1_lim.h
scrut/scrutinizer.o: /usr/include/bits/local_lim.h
scrut/scrutinizer.o: /usr/include/linux/limits.h
scrut/scrutinizer.o: /usr/include/bits/pthread_stack_min-dynamic.h
scrut/scrutinizer.o: /usr/include/bits/pthread_stack_min.h
scrut/scrutinizer.o: /usr/include/bits/posix2_lim.h common/stringbuf.h
scrut/scrutinizer.o: tagger/token.h tagger/word.h tagger/hashscatter.h
scrut/scrutinizer.o: tagger/inflectrule.h common/message.h tagger/tag.h
scrut/scrutinizer.o: tagger/bitmap.h common/file.h tagger/feature.h
scrut/scrutinizer.o: tagger/tagdefines.h tagger/wordtag.h scrut/element.h
scrut/scrutinizer.o: scrut/rule.h common/timer.h /usr/include/sys/time.h
scrut/scrutinizer.o: /usr/include/bits/types/time_t.h
scrut/scrutinizer.o: /usr/include/bits/types/struct_timeval.h
scrut/scrutinizer.o: /usr/include/sys/select.h /usr/include/bits/select.h
scrut/scrutinizer.o: /usr/include/bits/types/sigset_t.h
scrut/scrutinizer.o: /usr/include/bits/types/__sigset_t.h
scrut/scrutinizer.o: /usr/include/bits/types/struct_timespec.h
scrut/scrutinizer.o: tagger/sentence.h tagger/taglexicon.h tagger/hasharray.h
scrut/scrutinizer.o: tagger/tagtrigram.h scrut/matchingset.h scrut/rules.h
scrut/scrutinizer.o: tagger/text.h tagger/hashtable.h /usr/include/stdlib.h
scrut/scrutinizer.o: /usr/include/sys/types.h
scrut/scrutinizer.o: /usr/include/bits/types/clock_t.h
scrut/scrutinizer.o: /usr/include/bits/types/clockid_t.h
scrut/scrutinizer.o: /usr/include/bits/types/timer_t.h
scrut/scrutinizer.o: /usr/include/bits/stdint-intn.h /usr/include/endian.h
scrut/scrutinizer.o: /usr/include/bits/byteswap.h
scrut/scrutinizer.o: /usr/include/bits/uintn-identity.h
scrut/scrutinizer.o: /usr/include/bits/pthreadtypes.h
scrut/scrutinizer.o: /usr/include/bits/thread-shared-types.h
scrut/scrutinizer.o: /usr/include/bits/pthreadtypes-arch.h
scrut/scrutinizer.o: /usr/include/bits/atomic_wide_counter.h
scrut/scrutinizer.o: /usr/include/bits/struct_mutex.h
scrut/scrutinizer.o: /usr/include/bits/struct_rwlock.h /usr/include/alloca.h
scrut/scrutinizer.o: /usr/include/bits/stdlib-float.h
scrut/scrutinizer.o: scrut/evaluatedvariable.h scrut/semantictype.h
scrut/scrutinizer.o: scrut/operation.h scrut/expr.h scrut/rulesettings.h
scrut/scrutinizer.o: scrut/gramerror.h tagger/tagger.h tagger/lexicon.h
scrut/scrutinizer.o: tagger/morflexicon.h tagger/styleword.h
scrut/scrutinizer.o: tagger/newwordlexicon.h tagger/newword.h
scrut/scrutinizer.o: tagger/wordlexicon.h tagger/inflectlexicon.h
scrut/scrutinizer.o: tagger/wordruleterms.h token/tokenizer.h
scrut/scrutinizer.o: common/FlexLexer.h tagger/trigramgadget.h
scrut/scrutinizer.o: scrut/ruleset.h stava/stavaapi.h prob/prob.h
scrut/scrutinizer.o: prob/output.h ../misc/xmloutput.h prob/defines.h
scrut/scrutinizer.o: prob/report.h prob/probinfo.h prob/probmatch.h
scrut/scrutinizer.o: prob/probdefines.h
scrut/server_socket.o: /usr/include/arpa/inet.h /usr/include/features.h
scrut/server_socket.o: /usr/include/features-time64.h
scrut/server_socket.o: /usr/include/bits/wordsize.h
scrut/server_socket.o: /usr/include/bits/timesize.h
scrut/server_socket.o: /usr/include/stdc-predef.h /usr/include/sys/cdefs.h
scrut/server_socket.o: /usr/include/bits/long-double.h
scrut/server_socket.o: /usr/include/gnu/stubs.h /usr/include/netinet/in.h
scrut/server_socket.o: /usr/include/bits/stdint-uintn.h
scrut/server_socket.o: /usr/include/bits/types.h
scrut/server_socket.o: /usr/include/bits/typesizes.h
scrut/server_socket.o: /usr/include/bits/time64.h /usr/include/sys/socket.h
scrut/server_socket.o: /usr/include/bits/types/struct_iovec.h
scrut/server_socket.o: /usr/include/bits/socket.h /usr/include/sys/types.h
scrut/server_socket.o: /usr/include/bits/types/clock_t.h
scrut/server_socket.o: /usr/include/bits/types/clockid_t.h
scrut/server_socket.o: /usr/include/bits/types/time_t.h
scrut/server_socket.o: /usr/include/bits/types/timer_t.h
scrut/server_socket.o: /usr/include/bits/stdint-intn.h /usr/include/endian.h
scrut/server_socket.o: /usr/include/bits/endian.h
scrut/server_socket.o: /usr/include/bits/endianness.h
scrut/server_socket.o: /usr/include/bits/byteswap.h
scrut/server_socket.o: /usr/include/bits/uintn-identity.h
scrut/server_socket.o: /usr/include/sys/select.h /usr/include/bits/select.h
scrut/server_socket.o: /usr/include/bits/types/sigset_t.h
scrut/server_socket.o: /usr/include/bits/types/__sigset_t.h
scrut/server_socket.o: /usr/include/bits/types/struct_timeval.h
scrut/server_socket.o: /usr/include/bits/types/struct_timespec.h
scrut/server_socket.o: /usr/include/bits/pthreadtypes.h
scrut/server_socket.o: /usr/include/bits/thread-shared-types.h
scrut/server_socket.o: /usr/include/bits/pthreadtypes-arch.h
scrut/server_socket.o: /usr/include/bits/atomic_wide_counter.h
scrut/server_socket.o: /usr/include/bits/struct_mutex.h
scrut/server_socket.o: /usr/include/bits/struct_rwlock.h
scrut/server_socket.o: /usr/include/bits/socket_type.h
scrut/server_socket.o: /usr/include/bits/sockaddr.h /usr/include/asm/socket.h
scrut/server_socket.o: /usr/include/asm-generic/socket.h
scrut/server_socket.o: /usr/include/linux/posix_types.h
scrut/server_socket.o: /usr/include/linux/stddef.h
scrut/server_socket.o: /usr/include/asm/posix_types.h
scrut/server_socket.o: /usr/include/asm/posix_types_64.h
scrut/server_socket.o: /usr/include/asm-generic/posix_types.h
scrut/server_socket.o: /usr/include/asm/bitsperlong.h
scrut/server_socket.o: /usr/include/asm-generic/bitsperlong.h
scrut/server_socket.o: /usr/include/asm/sockios.h
scrut/server_socket.o: /usr/include/asm-generic/sockios.h
scrut/server_socket.o: /usr/include/bits/types/struct_osockaddr.h
scrut/server_socket.o: /usr/include/bits/in.h /usr/include/netdb.h
scrut/server_socket.o: /usr/include/rpc/netdb.h /usr/include/bits/netdb.h
scrut/server_socket.o: /usr/include/strings.h
scrut/server_socket.o: /usr/include/bits/types/locale_t.h
scrut/server_socket.o: /usr/include/bits/types/__locale_t.h
scrut/server_socket.o: scrut/server_socket.h scrut/socket.h
scrut/socket.o: /usr/include/netdb.h /usr/include/features.h
scrut/socket.o: /usr/include/features-time64.h /usr/include/bits/wordsize.h
scrut/socket.o: /usr/include/bits/timesize.h /usr/include/stdc-predef.h
scrut/socket.o: /usr/include/sys/cdefs.h /usr/include/bits/long-double.h
scrut/socket.o: /usr/include/gnu/stubs.h /usr/include/netinet/in.h
scrut/socket.o: /usr/include/bits/stdint-uintn.h /usr/include/bits/types.h
scrut/socket.o: /usr/include/bits/typesizes.h /usr/include/bits/time64.h
scrut/socket.o: /usr/include/sys/socket.h
scrut/socket.o: /usr/include/bits/types/struct_iovec.h
scrut/socket.o: /usr/include/bits/socket.h /usr/include/sys/types.h
scrut/socket.o: /usr/include/bits/types/clock_t.h
scrut/socket.o: /usr/include/bits/types/clockid_t.h
scrut/socket.o: /usr/include/bits/types/time_t.h
scrut/socket.o: /usr/include/bits/types/timer_t.h
scrut/socket.o: /usr/include/bits/stdint-intn.h /usr/include/endian.h
scrut/socket.o: /usr/include/bits/endian.h /usr/include/bits/endianness.h
scrut/socket.o: /usr/include/bits/byteswap.h
scrut/socket.o: /usr/include/bits/uintn-identity.h /usr/include/sys/select.h
scrut/socket.o: /usr/include/bits/select.h /usr/include/bits/types/sigset_t.h
scrut/socket.o: /usr/include/bits/types/__sigset_t.h
scrut/socket.o: /usr/include/bits/types/struct_timeval.h
scrut/socket.o: /usr/include/bits/types/struct_timespec.h
scrut/socket.o: /usr/include/bits/pthreadtypes.h
scrut/socket.o: /usr/include/bits/thread-shared-types.h
scrut/socket.o: /usr/include/bits/pthreadtypes-arch.h
scrut/socket.o: /usr/include/bits/atomic_wide_counter.h
scrut/socket.o: /usr/include/bits/struct_mutex.h
scrut/socket.o: /usr/include/bits/struct_rwlock.h
scrut/socket.o: /usr/include/bits/socket_type.h /usr/include/bits/sockaddr.h
scrut/socket.o: /usr/include/asm/socket.h /usr/include/asm-generic/socket.h
scrut/socket.o: /usr/include/linux/posix_types.h /usr/include/linux/stddef.h
scrut/socket.o: /usr/include/asm/posix_types.h
scrut/socket.o: /usr/include/asm/posix_types_64.h
scrut/socket.o: /usr/include/asm-generic/posix_types.h
scrut/socket.o: /usr/include/asm/bitsperlong.h
scrut/socket.o: /usr/include/asm-generic/bitsperlong.h
scrut/socket.o: /usr/include/asm/sockios.h /usr/include/asm-generic/sockios.h
scrut/socket.o: /usr/include/bits/types/struct_osockaddr.h
scrut/socket.o: /usr/include/bits/in.h /usr/include/rpc/netdb.h
scrut/socket.o: /usr/include/bits/netdb.h /usr/include/strings.h
scrut/socket.o: /usr/include/bits/types/locale_t.h
scrut/socket.o: /usr/include/bits/types/__locale_t.h /usr/include/unistd.h
scrut/socket.o: /usr/include/bits/posix_opt.h
scrut/socket.o: /usr/include/bits/environments.h /usr/include/bits/confname.h
scrut/socket.o: /usr/include/bits/getopt_posix.h
scrut/socket.o: /usr/include/bits/getopt_core.h
scrut/socket.o: /usr/include/bits/unistd_ext.h scrut/socket.h
scrut/socket.o: /usr/include/arpa/inet.h
scrut/web.o: /usr/include/errno.h /usr/include/features.h
scrut/web.o: /usr/include/features-time64.h /usr/include/bits/wordsize.h
scrut/web.o: /usr/include/bits/timesize.h /usr/include/stdc-predef.h
scrut/web.o: /usr/include/sys/cdefs.h /usr/include/bits/long-double.h
scrut/web.o: /usr/include/gnu/stubs.h /usr/include/bits/errno.h
scrut/web.o: /usr/include/linux/errno.h /usr/include/asm/errno.h
scrut/web.o: /usr/include/asm-generic/errno.h
scrut/web.o: /usr/include/asm-generic/errno-base.h scrut/server_socket.h
scrut/web.o: scrut/socket.h /usr/include/arpa/inet.h
scrut/web.o: /usr/include/netinet/in.h /usr/include/bits/stdint-uintn.h
scrut/web.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
scrut/web.o: /usr/include/bits/time64.h /usr/include/sys/socket.h
scrut/web.o: /usr/include/bits/types/struct_iovec.h
scrut/web.o: /usr/include/bits/socket.h /usr/include/sys/types.h
scrut/web.o: /usr/include/bits/types/clock_t.h
scrut/web.o: /usr/include/bits/types/clockid_t.h
scrut/web.o: /usr/include/bits/types/time_t.h
scrut/web.o: /usr/include/bits/types/timer_t.h
scrut/web.o: /usr/include/bits/stdint-intn.h /usr/include/endian.h
scrut/web.o: /usr/include/bits/endian.h /usr/include/bits/endianness.h
scrut/web.o: /usr/include/bits/byteswap.h /usr/include/bits/uintn-identity.h
scrut/web.o: /usr/include/sys/select.h /usr/include/bits/select.h
scrut/web.o: /usr/include/bits/types/sigset_t.h
scrut/web.o: /usr/include/bits/types/__sigset_t.h
scrut/web.o: /usr/include/bits/types/struct_timeval.h
scrut/web.o: /usr/include/bits/types/struct_timespec.h
scrut/web.o: /usr/include/bits/pthreadtypes.h
scrut/web.o: /usr/include/bits/thread-shared-types.h
scrut/web.o: /usr/include/bits/pthreadtypes-arch.h
scrut/web.o: /usr/include/bits/atomic_wide_counter.h
scrut/web.o: /usr/include/bits/struct_mutex.h
scrut/web.o: /usr/include/bits/struct_rwlock.h
scrut/web.o: /usr/include/bits/socket_type.h /usr/include/bits/sockaddr.h
scrut/web.o: /usr/include/asm/socket.h /usr/include/asm-generic/socket.h
scrut/web.o: /usr/include/linux/posix_types.h /usr/include/linux/stddef.h
scrut/web.o: /usr/include/asm/posix_types.h /usr/include/asm/posix_types_64.h
scrut/web.o: /usr/include/asm-generic/posix_types.h
scrut/web.o: /usr/include/asm/bitsperlong.h
scrut/web.o: /usr/include/asm-generic/bitsperlong.h
scrut/web.o: /usr/include/asm/sockios.h /usr/include/asm-generic/sockios.h
scrut/web.o: /usr/include/bits/types/struct_osockaddr.h
scrut/web.o: /usr/include/bits/in.h scrut/scrutinizer.h scrut/matching.h
scrut/web.o: tagger/wordtoken.h tagger/letter.h /usr/include/string.h
scrut/web.o: /usr/include/bits/libc-header-start.h
scrut/web.o: /usr/include/bits/types/locale_t.h
scrut/web.o: /usr/include/bits/types/__locale_t.h /usr/include/strings.h
scrut/web.o: /usr/include/ctype.h common/basics.h /usr/include/stdio.h
scrut/web.o: /usr/include/bits/types/__fpos_t.h
scrut/web.o: /usr/include/bits/types/__mbstate_t.h
scrut/web.o: /usr/include/bits/types/__fpos64_t.h
scrut/web.o: /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h
scrut/web.o: /usr/include/bits/types/struct_FILE.h
scrut/web.o: /usr/include/bits/types/cookie_io_functions_t.h
scrut/web.o: /usr/include/bits/stdio_lim.h /usr/include/bits/floatn.h
scrut/web.o: /usr/include/bits/floatn-common.h common/ensure.h
scrut/web.o: /usr/include/assert.h tagger/settings.h /usr/include/limits.h
scrut/web.o: /usr/include/bits/posix1_lim.h /usr/include/bits/local_lim.h
scrut/web.o: /usr/include/linux/limits.h
scrut/web.o: /usr/include/bits/pthread_stack_min-dynamic.h
scrut/web.o: /usr/include/bits/pthread_stack_min.h
scrut/web.o: /usr/include/bits/posix2_lim.h common/stringbuf.h tagger/token.h
scrut/web.o: tagger/word.h tagger/hashscatter.h tagger/inflectrule.h
scrut/web.o: common/message.h tagger/tag.h tagger/bitmap.h common/file.h
scrut/web.o: tagger/feature.h tagger/tagdefines.h tagger/wordtag.h
scrut/web.o: scrut/element.h scrut/rule.h common/timer.h
scrut/web.o: /usr/include/sys/time.h tagger/sentence.h tagger/taglexicon.h
scrut/web.o: tagger/hasharray.h tagger/tagtrigram.h scrut/matchingset.h
scrut/web.o: scrut/rules.h tagger/text.h tagger/hashtable.h
scrut/web.o: /usr/include/stdlib.h /usr/include/alloca.h
scrut/web.o: /usr/include/bits/stdlib-float.h scrut/evaluatedvariable.h
scrut/web.o: scrut/semantictype.h scrut/operation.h scrut/expr.h
scrut/web.o: scrut/rulesettings.h scrut/gramerror.h tagger/tagger.h
scrut/web.o: tagger/lexicon.h tagger/morflexicon.h tagger/styleword.h
scrut/web.o: tagger/newwordlexicon.h tagger/newword.h tagger/wordlexicon.h
scrut/web.o: tagger/inflectlexicon.h tagger/wordruleterms.h token/tokenizer.h
scrut/web.o: common/FlexLexer.h tagger/trigramgadget.h prob/output.h
scrut/web.o: ../misc/xmloutput.h prob/prob.h
tagger/hashscatter.o: tagger/hashscatter.h tagger/letter.h
tagger/hashscatter.o: /usr/include/string.h
tagger/hashscatter.o: /usr/include/bits/libc-header-start.h
tagger/hashscatter.o: /usr/include/features.h /usr/include/features-time64.h
tagger/hashscatter.o: /usr/include/bits/wordsize.h
tagger/hashscatter.o: /usr/include/bits/timesize.h /usr/include/stdc-predef.h
tagger/hashscatter.o: /usr/include/sys/cdefs.h
tagger/hashscatter.o: /usr/include/bits/long-double.h
tagger/hashscatter.o: /usr/include/gnu/stubs.h
tagger/hashscatter.o: /usr/include/bits/types/locale_t.h
tagger/hashscatter.o: /usr/include/bits/types/__locale_t.h
tagger/hashscatter.o: /usr/include/strings.h /usr/include/ctype.h
tagger/hashscatter.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
tagger/hashscatter.o: /usr/include/bits/time64.h /usr/include/bits/endian.h
tagger/hashscatter.o: /usr/include/bits/endianness.h common/basics.h
tagger/hashscatter.o: /usr/include/stdio.h /usr/include/bits/types/__fpos_t.h
tagger/hashscatter.o: /usr/include/bits/types/__mbstate_t.h
tagger/hashscatter.o: /usr/include/bits/types/__fpos64_t.h
tagger/hashscatter.o: /usr/include/bits/types/__FILE.h
tagger/hashscatter.o: /usr/include/bits/types/FILE.h
tagger/hashscatter.o: /usr/include/bits/types/struct_FILE.h
tagger/hashscatter.o: /usr/include/bits/types/cookie_io_functions_t.h
tagger/hashscatter.o: /usr/include/bits/stdio_lim.h
tagger/hashscatter.o: /usr/include/bits/floatn.h
tagger/hashscatter.o: /usr/include/bits/floatn-common.h common/ensure.h
tagger/hashscatter.o: /usr/include/assert.h
tagger/inflectlexicon.o: common/file.h /usr/include/ctype.h
tagger/inflectlexicon.o: /usr/include/features.h
tagger/inflectlexicon.o: /usr/include/features-time64.h
tagger/inflectlexicon.o: /usr/include/bits/wordsize.h
tagger/inflectlexicon.o: /usr/include/bits/timesize.h
tagger/inflectlexicon.o: /usr/include/stdc-predef.h /usr/include/sys/cdefs.h
tagger/inflectlexicon.o: /usr/include/bits/long-double.h
tagger/inflectlexicon.o: /usr/include/gnu/stubs.h /usr/include/bits/types.h
tagger/inflectlexicon.o: /usr/include/bits/typesizes.h
tagger/inflectlexicon.o: /usr/include/bits/time64.h
tagger/inflectlexicon.o: /usr/include/bits/endian.h
tagger/inflectlexicon.o: /usr/include/bits/endianness.h
tagger/inflectlexicon.o: /usr/include/bits/types/locale_t.h
tagger/inflectlexicon.o: /usr/include/bits/types/__locale_t.h common/ensure.h
tagger/inflectlexicon.o: /usr/include/assert.h common/message.h
tagger/inflectlexicon.o: tagger/inflectlexicon.h common/basics.h
tagger/inflectlexicon.o: /usr/include/stdio.h
tagger/inflectlexicon.o: /usr/include/bits/libc-header-start.h
tagger/inflectlexicon.o: /usr/include/bits/types/__fpos_t.h
tagger/inflectlexicon.o: /usr/include/bits/types/__mbstate_t.h
tagger/inflectlexicon.o: /usr/include/bits/types/__fpos64_t.h
tagger/inflectlexicon.o: /usr/include/bits/types/__FILE.h
tagger/inflectlexicon.o: /usr/include/bits/types/FILE.h
tagger/inflectlexicon.o: /usr/include/bits/types/struct_FILE.h
tagger/inflectlexicon.o: /usr/include/bits/types/cookie_io_functions_t.h
tagger/inflectlexicon.o: /usr/include/bits/stdio_lim.h
tagger/inflectlexicon.o: /usr/include/bits/floatn.h
tagger/inflectlexicon.o: /usr/include/bits/floatn-common.h
tagger/inflectlexicon.o: tagger/inflectrule.h /usr/include/limits.h
tagger/inflectlexicon.o: /usr/include/bits/posix1_lim.h
tagger/inflectlexicon.o: /usr/include/bits/local_lim.h
tagger/inflectlexicon.o: /usr/include/linux/limits.h
tagger/inflectlexicon.o: /usr/include/bits/pthread_stack_min-dynamic.h
tagger/inflectlexicon.o: /usr/include/bits/pthread_stack_min.h
tagger/inflectlexicon.o: /usr/include/bits/posix2_lim.h tagger/tag.h
tagger/inflectlexicon.o: /usr/include/string.h /usr/include/strings.h
tagger/inflectlexicon.o: tagger/bitmap.h tagger/feature.h
tagger/inflectlexicon.o: tagger/hashscatter.h tagger/settings.h
tagger/inflectlexicon.o: tagger/tagdefines.h tagger/letter.h
tagger/inflectlexicon.o: tagger/taglexicon.h tagger/hasharray.h
tagger/inflectlexicon.o: tagger/tagtrigram.h tagger/token.h tagger/word.h
tagger/inflectlexicon.o: tagger/wordtag.h common/stringbuf.h
tagger/inflectrule.o: tagger/letter.h /usr/include/string.h
tagger/inflectrule.o: /usr/include/bits/libc-header-start.h
tagger/inflectrule.o: /usr/include/features.h /usr/include/features-time64.h
tagger/inflectrule.o: /usr/include/bits/wordsize.h
tagger/inflectrule.o: /usr/include/bits/timesize.h /usr/include/stdc-predef.h
tagger/inflectrule.o: /usr/include/sys/cdefs.h
tagger/inflectrule.o: /usr/include/bits/long-double.h
tagger/inflectrule.o: /usr/include/gnu/stubs.h
tagger/inflectrule.o: /usr/include/bits/types/locale_t.h
tagger/inflectrule.o: /usr/include/bits/types/__locale_t.h
tagger/inflectrule.o: /usr/include/strings.h /usr/include/ctype.h
tagger/inflectrule.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
tagger/inflectrule.o: /usr/include/bits/time64.h /usr/include/bits/endian.h
tagger/inflectrule.o: /usr/include/bits/endianness.h common/basics.h
tagger/inflectrule.o: /usr/include/stdio.h /usr/include/bits/types/__fpos_t.h
tagger/inflectrule.o: /usr/include/bits/types/__mbstate_t.h
tagger/inflectrule.o: /usr/include/bits/types/__fpos64_t.h
tagger/inflectrule.o: /usr/include/bits/types/__FILE.h
tagger/inflectrule.o: /usr/include/bits/types/FILE.h
tagger/inflectrule.o: /usr/include/bits/types/struct_FILE.h
tagger/inflectrule.o: /usr/include/bits/types/cookie_io_functions_t.h
tagger/inflectrule.o: /usr/include/bits/stdio_lim.h
tagger/inflectrule.o: /usr/include/bits/floatn.h
tagger/inflectrule.o: /usr/include/bits/floatn-common.h common/ensure.h
tagger/inflectrule.o: /usr/include/assert.h tagger/inflectrule.h
tagger/inflectrule.o: /usr/include/limits.h /usr/include/bits/posix1_lim.h
tagger/inflectrule.o: /usr/include/bits/local_lim.h
tagger/inflectrule.o: /usr/include/linux/limits.h
tagger/inflectrule.o: /usr/include/bits/pthread_stack_min-dynamic.h
tagger/inflectrule.o: /usr/include/bits/pthread_stack_min.h
tagger/inflectrule.o: /usr/include/bits/posix2_lim.h tagger/tag.h
tagger/inflectrule.o: tagger/bitmap.h common/file.h common/message.h
tagger/inflectrule.o: tagger/feature.h tagger/hashscatter.h tagger/settings.h
tagger/inflectrule.o: tagger/tagdefines.h
tagger/letter.o: tagger/letter.h /usr/include/string.h
tagger/letter.o: /usr/include/bits/libc-header-start.h
tagger/letter.o: /usr/include/features.h /usr/include/features-time64.h
tagger/letter.o: /usr/include/bits/wordsize.h /usr/include/bits/timesize.h
tagger/letter.o: /usr/include/stdc-predef.h /usr/include/sys/cdefs.h
tagger/letter.o: /usr/include/bits/long-double.h /usr/include/gnu/stubs.h
tagger/letter.o: /usr/include/bits/types/locale_t.h
tagger/letter.o: /usr/include/bits/types/__locale_t.h /usr/include/strings.h
tagger/letter.o: /usr/include/ctype.h /usr/include/bits/types.h
tagger/letter.o: /usr/include/bits/typesizes.h /usr/include/bits/time64.h
tagger/letter.o: /usr/include/bits/endian.h /usr/include/bits/endianness.h
tagger/letter.o: common/basics.h /usr/include/stdio.h
tagger/letter.o: /usr/include/bits/types/__fpos_t.h
tagger/letter.o: /usr/include/bits/types/__mbstate_t.h
tagger/letter.o: /usr/include/bits/types/__fpos64_t.h
tagger/letter.o: /usr/include/bits/types/__FILE.h
tagger/letter.o: /usr/include/bits/types/FILE.h
tagger/letter.o: /usr/include/bits/types/struct_FILE.h
tagger/letter.o: /usr/include/bits/types/cookie_io_functions_t.h
tagger/letter.o: /usr/include/bits/stdio_lim.h /usr/include/bits/floatn.h
tagger/letter.o: /usr/include/bits/floatn-common.h common/ensure.h
tagger/letter.o: /usr/include/assert.h
tagger/lexicon.o: /usr/include/math.h /usr/include/bits/libc-header-start.h
tagger/lexicon.o: /usr/include/features.h /usr/include/features-time64.h
tagger/lexicon.o: /usr/include/bits/wordsize.h /usr/include/bits/timesize.h
tagger/lexicon.o: /usr/include/stdc-predef.h /usr/include/sys/cdefs.h
tagger/lexicon.o: /usr/include/bits/long-double.h /usr/include/gnu/stubs.h
tagger/lexicon.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
tagger/lexicon.o: /usr/include/bits/time64.h /usr/include/bits/math-vector.h
tagger/lexicon.o: /usr/include/bits/libm-simd-decl-stubs.h
tagger/lexicon.o: /usr/include/bits/floatn.h
tagger/lexicon.o: /usr/include/bits/floatn-common.h
tagger/lexicon.o: /usr/include/bits/flt-eval-method.h
tagger/lexicon.o: /usr/include/bits/fp-logb.h /usr/include/bits/fp-fast.h
tagger/lexicon.o: /usr/include/bits/mathcalls-macros.h
tagger/lexicon.o: /usr/include/bits/mathcalls-helper-functions.h
tagger/lexicon.o: /usr/include/bits/mathcalls.h
tagger/lexicon.o: /usr/include/bits/mathcalls-narrow.h
tagger/lexicon.o: /usr/include/bits/iscanonical.h common/file.h
tagger/lexicon.o: /usr/include/ctype.h /usr/include/bits/endian.h
tagger/lexicon.o: /usr/include/bits/endianness.h
tagger/lexicon.o: /usr/include/bits/types/locale_t.h
tagger/lexicon.o: /usr/include/bits/types/__locale_t.h common/ensure.h
tagger/lexicon.o: /usr/include/assert.h common/message.h tagger/letter.h
tagger/lexicon.o: /usr/include/string.h /usr/include/strings.h
tagger/lexicon.o: common/basics.h /usr/include/stdio.h
tagger/lexicon.o: /usr/include/bits/types/__fpos_t.h
tagger/lexicon.o: /usr/include/bits/types/__mbstate_t.h
tagger/lexicon.o: /usr/include/bits/types/__fpos64_t.h
tagger/lexicon.o: /usr/include/bits/types/__FILE.h
tagger/lexicon.o: /usr/include/bits/types/FILE.h
tagger/lexicon.o: /usr/include/bits/types/struct_FILE.h
tagger/lexicon.o: /usr/include/bits/types/cookie_io_functions_t.h
tagger/lexicon.o: /usr/include/bits/stdio_lim.h tagger/morf.h
tagger/lexicon.o: tagger/sentence.h tagger/wordtoken.h tagger/settings.h
tagger/lexicon.o: /usr/include/limits.h /usr/include/bits/posix1_lim.h
tagger/lexicon.o: /usr/include/bits/local_lim.h /usr/include/linux/limits.h
tagger/lexicon.o: /usr/include/bits/pthread_stack_min-dynamic.h
tagger/lexicon.o: /usr/include/bits/pthread_stack_min.h
tagger/lexicon.o: /usr/include/bits/posix2_lim.h common/stringbuf.h
tagger/lexicon.o: tagger/token.h tagger/word.h tagger/hashscatter.h
tagger/lexicon.o: tagger/inflectrule.h tagger/tag.h tagger/bitmap.h
tagger/lexicon.o: tagger/feature.h tagger/tagdefines.h tagger/wordtag.h
tagger/lexicon.o: tagger/lexicon.h tagger/hashtable.h /usr/include/stdlib.h
tagger/lexicon.o: /usr/include/sys/types.h /usr/include/bits/types/clock_t.h
tagger/lexicon.o: /usr/include/bits/types/clockid_t.h
tagger/lexicon.o: /usr/include/bits/types/time_t.h
tagger/lexicon.o: /usr/include/bits/types/timer_t.h
tagger/lexicon.o: /usr/include/bits/stdint-intn.h /usr/include/endian.h
tagger/lexicon.o: /usr/include/bits/byteswap.h
tagger/lexicon.o: /usr/include/bits/uintn-identity.h
tagger/lexicon.o: /usr/include/sys/select.h /usr/include/bits/select.h
tagger/lexicon.o: /usr/include/bits/types/sigset_t.h
tagger/lexicon.o: /usr/include/bits/types/__sigset_t.h
tagger/lexicon.o: /usr/include/bits/types/struct_timeval.h
tagger/lexicon.o: /usr/include/bits/types/struct_timespec.h
tagger/lexicon.o: /usr/include/bits/pthreadtypes.h
tagger/lexicon.o: /usr/include/bits/thread-shared-types.h
tagger/lexicon.o: /usr/include/bits/pthreadtypes-arch.h
tagger/lexicon.o: /usr/include/bits/atomic_wide_counter.h
tagger/lexicon.o: /usr/include/bits/struct_mutex.h
tagger/lexicon.o: /usr/include/bits/struct_rwlock.h /usr/include/alloca.h
tagger/lexicon.o: /usr/include/bits/stdlib-float.h tagger/morflexicon.h
tagger/lexicon.o: tagger/hasharray.h tagger/taglexicon.h tagger/tagtrigram.h
tagger/lexicon.o: tagger/styleword.h tagger/newwordlexicon.h tagger/newword.h
tagger/lexicon.o: tagger/wordlexicon.h tagger/inflectlexicon.h
tagger/lexicon.o: tagger/wordruleterms.h tagger/tagger.h common/timer.h
tagger/lexicon.o: /usr/include/sys/time.h tagger/text.h token/tokenizer.h
tagger/lexicon.o: common/FlexLexer.h tagger/trigramgadget.h
tagger/main.o: common/file.h /usr/include/ctype.h /usr/include/features.h
tagger/main.o: /usr/include/features-time64.h /usr/include/bits/wordsize.h
tagger/main.o: /usr/include/bits/timesize.h /usr/include/stdc-predef.h
tagger/main.o: /usr/include/sys/cdefs.h /usr/include/bits/long-double.h
tagger/main.o: /usr/include/gnu/stubs.h /usr/include/bits/types.h
tagger/main.o: /usr/include/bits/typesizes.h /usr/include/bits/time64.h
tagger/main.o: /usr/include/bits/endian.h /usr/include/bits/endianness.h
tagger/main.o: /usr/include/bits/types/locale_t.h
tagger/main.o: /usr/include/bits/types/__locale_t.h common/ensure.h
tagger/main.o: /usr/include/assert.h common/message.h tagger/letter.h
tagger/main.o: /usr/include/string.h /usr/include/bits/libc-header-start.h
tagger/main.o: /usr/include/strings.h common/basics.h /usr/include/stdio.h
tagger/main.o: /usr/include/bits/types/__fpos_t.h
tagger/main.o: /usr/include/bits/types/__mbstate_t.h
tagger/main.o: /usr/include/bits/types/__fpos64_t.h
tagger/main.o: /usr/include/bits/types/__FILE.h
tagger/main.o: /usr/include/bits/types/FILE.h
tagger/main.o: /usr/include/bits/types/struct_FILE.h
tagger/main.o: /usr/include/bits/types/cookie_io_functions_t.h
tagger/main.o: /usr/include/bits/stdio_lim.h /usr/include/bits/floatn.h
tagger/main.o: /usr/include/bits/floatn-common.h tagger/settings.h
tagger/main.o: /usr/include/limits.h /usr/include/bits/posix1_lim.h
tagger/main.o: /usr/include/bits/local_lim.h /usr/include/linux/limits.h
tagger/main.o: /usr/include/bits/pthread_stack_min-dynamic.h
tagger/main.o: /usr/include/bits/pthread_stack_min.h
tagger/main.o: /usr/include/bits/posix2_lim.h tagger/tagger.h
tagger/main.o: tagger/lexicon.h tagger/hashtable.h /usr/include/stdlib.h
tagger/main.o: /usr/include/sys/types.h /usr/include/bits/types/clock_t.h
tagger/main.o: /usr/include/bits/types/clockid_t.h
tagger/main.o: /usr/include/bits/types/time_t.h
tagger/main.o: /usr/include/bits/types/timer_t.h
tagger/main.o: /usr/include/bits/stdint-intn.h /usr/include/endian.h
tagger/main.o: /usr/include/bits/byteswap.h
tagger/main.o: /usr/include/bits/uintn-identity.h /usr/include/sys/select.h
tagger/main.o: /usr/include/bits/select.h /usr/include/bits/types/sigset_t.h
tagger/main.o: /usr/include/bits/types/__sigset_t.h
tagger/main.o: /usr/include/bits/types/struct_timeval.h
tagger/main.o: /usr/include/bits/types/struct_timespec.h
tagger/main.o: /usr/include/bits/pthreadtypes.h
tagger/main.o: /usr/include/bits/thread-shared-types.h
tagger/main.o: /usr/include/bits/pthreadtypes-arch.h
tagger/main.o: /usr/include/bits/atomic_wide_counter.h
tagger/main.o: /usr/include/bits/struct_mutex.h
tagger/main.o: /usr/include/bits/struct_rwlock.h /usr/include/alloca.h
tagger/main.o: /usr/include/bits/stdlib-float.h tagger/morflexicon.h
tagger/main.o: tagger/word.h tagger/hashscatter.h tagger/inflectrule.h
tagger/main.o: tagger/tag.h tagger/bitmap.h tagger/feature.h
tagger/main.o: tagger/tagdefines.h tagger/wordtag.h common/stringbuf.h
tagger/main.o: tagger/hasharray.h tagger/taglexicon.h tagger/tagtrigram.h
tagger/main.o: tagger/token.h tagger/styleword.h tagger/newwordlexicon.h
tagger/main.o: tagger/newword.h tagger/wordlexicon.h tagger/inflectlexicon.h
tagger/main.o: tagger/wordruleterms.h tagger/sentence.h tagger/wordtoken.h
tagger/main.o: common/timer.h /usr/include/sys/time.h tagger/text.h
tagger/main.o: token/tokenizer.h common/FlexLexer.h tagger/trigramgadget.h
tagger/morflexicon.o: common/file.h /usr/include/ctype.h
tagger/morflexicon.o: /usr/include/features.h /usr/include/features-time64.h
tagger/morflexicon.o: /usr/include/bits/wordsize.h
tagger/morflexicon.o: /usr/include/bits/timesize.h /usr/include/stdc-predef.h
tagger/morflexicon.o: /usr/include/sys/cdefs.h
tagger/morflexicon.o: /usr/include/bits/long-double.h
tagger/morflexicon.o: /usr/include/gnu/stubs.h /usr/include/bits/types.h
tagger/morflexicon.o: /usr/include/bits/typesizes.h
tagger/morflexicon.o: /usr/include/bits/time64.h /usr/include/bits/endian.h
tagger/morflexicon.o: /usr/include/bits/endianness.h
tagger/morflexicon.o: /usr/include/bits/types/locale_t.h
tagger/morflexicon.o: /usr/include/bits/types/__locale_t.h common/ensure.h
tagger/morflexicon.o: /usr/include/assert.h common/message.h
tagger/morflexicon.o: tagger/morflexicon.h tagger/word.h
tagger/morflexicon.o: /usr/include/string.h
tagger/morflexicon.o: /usr/include/bits/libc-header-start.h
tagger/morflexicon.o: /usr/include/strings.h tagger/hashscatter.h
tagger/morflexicon.o: tagger/inflectrule.h common/basics.h
tagger/morflexicon.o: /usr/include/stdio.h /usr/include/bits/types/__fpos_t.h
tagger/morflexicon.o: /usr/include/bits/types/__mbstate_t.h
tagger/morflexicon.o: /usr/include/bits/types/__fpos64_t.h
tagger/morflexicon.o: /usr/include/bits/types/__FILE.h
tagger/morflexicon.o: /usr/include/bits/types/FILE.h
tagger/morflexicon.o: /usr/include/bits/types/struct_FILE.h
tagger/morflexicon.o: /usr/include/bits/types/cookie_io_functions_t.h
tagger/morflexicon.o: /usr/include/bits/stdio_lim.h
tagger/morflexicon.o: /usr/include/bits/floatn.h
tagger/morflexicon.o: /usr/include/bits/floatn-common.h /usr/include/limits.h
tagger/morflexicon.o: /usr/include/bits/posix1_lim.h
tagger/morflexicon.o: /usr/include/bits/local_lim.h
tagger/morflexicon.o: /usr/include/linux/limits.h
tagger/morflexicon.o: /usr/include/bits/pthread_stack_min-dynamic.h
tagger/morflexicon.o: /usr/include/bits/pthread_stack_min.h
tagger/morflexicon.o: /usr/include/bits/posix2_lim.h tagger/tag.h
tagger/morflexicon.o: tagger/bitmap.h tagger/feature.h tagger/settings.h
tagger/morflexicon.o: tagger/tagdefines.h tagger/wordtag.h common/stringbuf.h
tagger/morflexicon.o: tagger/hasharray.h tagger/taglexicon.h
tagger/morflexicon.o: tagger/tagtrigram.h tagger/token.h tagger/styleword.h
tagger/newwordlexicon.o: tagger/newwordlexicon.h tagger/newword.h
tagger/newwordlexicon.o: tagger/word.h /usr/include/string.h
tagger/newwordlexicon.o: /usr/include/bits/libc-header-start.h
tagger/newwordlexicon.o: /usr/include/features.h
tagger/newwordlexicon.o: /usr/include/features-time64.h
tagger/newwordlexicon.o: /usr/include/bits/wordsize.h
tagger/newwordlexicon.o: /usr/include/bits/timesize.h
tagger/newwordlexicon.o: /usr/include/stdc-predef.h /usr/include/sys/cdefs.h
tagger/newwordlexicon.o: /usr/include/bits/long-double.h
tagger/newwordlexicon.o: /usr/include/gnu/stubs.h
tagger/newwordlexicon.o: /usr/include/bits/types/locale_t.h
tagger/newwordlexicon.o: /usr/include/bits/types/__locale_t.h
tagger/newwordlexicon.o: /usr/include/strings.h tagger/hashscatter.h
tagger/newwordlexicon.o: tagger/inflectrule.h common/basics.h
tagger/newwordlexicon.o: /usr/include/stdio.h /usr/include/bits/types.h
tagger/newwordlexicon.o: /usr/include/bits/typesizes.h
tagger/newwordlexicon.o: /usr/include/bits/time64.h
tagger/newwordlexicon.o: /usr/include/bits/types/__fpos_t.h
tagger/newwordlexicon.o: /usr/include/bits/types/__mbstate_t.h
tagger/newwordlexicon.o: /usr/include/bits/types/__fpos64_t.h
tagger/newwordlexicon.o: /usr/include/bits/types/__FILE.h
tagger/newwordlexicon.o: /usr/include/bits/types/FILE.h
tagger/newwordlexicon.o: /usr/include/bits/types/struct_FILE.h
tagger/newwordlexicon.o: /usr/include/bits/types/cookie_io_functions_t.h
tagger/newwordlexicon.o: /usr/include/bits/stdio_lim.h
tagger/newwordlexicon.o: /usr/include/bits/floatn.h
tagger/newwordlexicon.o: /usr/include/bits/floatn-common.h common/ensure.h
tagger/newwordlexicon.o: /usr/include/assert.h /usr/include/limits.h
tagger/newwordlexicon.o: /usr/include/bits/posix1_lim.h
tagger/newwordlexicon.o: /usr/include/bits/local_lim.h
tagger/newwordlexicon.o: /usr/include/linux/limits.h
tagger/newwordlexicon.o: /usr/include/bits/pthread_stack_min-dynamic.h
tagger/newwordlexicon.o: /usr/include/bits/pthread_stack_min.h
tagger/newwordlexicon.o: /usr/include/bits/posix2_lim.h common/message.h
tagger/newwordlexicon.o: tagger/tag.h tagger/bitmap.h common/file.h
tagger/newwordlexicon.o: /usr/include/ctype.h /usr/include/bits/endian.h
tagger/newwordlexicon.o: /usr/include/bits/endianness.h tagger/feature.h
tagger/newwordlexicon.o: tagger/settings.h tagger/tagdefines.h
tagger/newwordlexicon.o: tagger/wordtag.h common/stringbuf.h
tagger/newwordlexicon.o: tagger/hashtable.h /usr/include/stdlib.h
tagger/newwordlexicon.o: /usr/include/sys/types.h
tagger/newwordlexicon.o: /usr/include/bits/types/clock_t.h
tagger/newwordlexicon.o: /usr/include/bits/types/clockid_t.h
tagger/newwordlexicon.o: /usr/include/bits/types/time_t.h
tagger/newwordlexicon.o: /usr/include/bits/types/timer_t.h
tagger/newwordlexicon.o: /usr/include/bits/stdint-intn.h
tagger/newwordlexicon.o: /usr/include/endian.h /usr/include/bits/byteswap.h
tagger/newwordlexicon.o: /usr/include/bits/uintn-identity.h
tagger/newwordlexicon.o: /usr/include/sys/select.h /usr/include/bits/select.h
tagger/newwordlexicon.o: /usr/include/bits/types/sigset_t.h
tagger/newwordlexicon.o: /usr/include/bits/types/__sigset_t.h
tagger/newwordlexicon.o: /usr/include/bits/types/struct_timeval.h
tagger/newwordlexicon.o: /usr/include/bits/types/struct_timespec.h
tagger/newwordlexicon.o: /usr/include/bits/pthreadtypes.h
tagger/newwordlexicon.o: /usr/include/bits/thread-shared-types.h
tagger/newwordlexicon.o: /usr/include/bits/pthreadtypes-arch.h
tagger/newwordlexicon.o: /usr/include/bits/atomic_wide_counter.h
tagger/newwordlexicon.o: /usr/include/bits/struct_mutex.h
tagger/newwordlexicon.o: /usr/include/bits/struct_rwlock.h
tagger/newwordlexicon.o: /usr/include/alloca.h
tagger/newwordlexicon.o: /usr/include/bits/stdlib-float.h
tagger/sentence.o: tagger/letter.h /usr/include/string.h
tagger/sentence.o: /usr/include/bits/libc-header-start.h
tagger/sentence.o: /usr/include/features.h /usr/include/features-time64.h
tagger/sentence.o: /usr/include/bits/wordsize.h /usr/include/bits/timesize.h
tagger/sentence.o: /usr/include/stdc-predef.h /usr/include/sys/cdefs.h
tagger/sentence.o: /usr/include/bits/long-double.h /usr/include/gnu/stubs.h
tagger/sentence.o: /usr/include/bits/types/locale_t.h
tagger/sentence.o: /usr/include/bits/types/__locale_t.h
tagger/sentence.o: /usr/include/strings.h /usr/include/ctype.h
tagger/sentence.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
tagger/sentence.o: /usr/include/bits/time64.h /usr/include/bits/endian.h
tagger/sentence.o: /usr/include/bits/endianness.h common/basics.h
tagger/sentence.o: /usr/include/stdio.h /usr/include/bits/types/__fpos_t.h
tagger/sentence.o: /usr/include/bits/types/__mbstate_t.h
tagger/sentence.o: /usr/include/bits/types/__fpos64_t.h
tagger/sentence.o: /usr/include/bits/types/__FILE.h
tagger/sentence.o: /usr/include/bits/types/FILE.h
tagger/sentence.o: /usr/include/bits/types/struct_FILE.h
tagger/sentence.o: /usr/include/bits/types/cookie_io_functions_t.h
tagger/sentence.o: /usr/include/bits/stdio_lim.h /usr/include/bits/floatn.h
tagger/sentence.o: /usr/include/bits/floatn-common.h common/ensure.h
tagger/sentence.o: /usr/include/assert.h tagger/sentence.h tagger/wordtoken.h
tagger/sentence.o: tagger/settings.h /usr/include/limits.h
tagger/sentence.o: /usr/include/bits/posix1_lim.h
tagger/sentence.o: /usr/include/bits/local_lim.h /usr/include/linux/limits.h
tagger/sentence.o: /usr/include/bits/pthread_stack_min-dynamic.h
tagger/sentence.o: /usr/include/bits/pthread_stack_min.h
tagger/sentence.o: /usr/include/bits/posix2_lim.h common/stringbuf.h
tagger/sentence.o: tagger/token.h tagger/word.h tagger/hashscatter.h
tagger/sentence.o: tagger/inflectrule.h common/message.h tagger/tag.h
tagger/sentence.o: tagger/bitmap.h common/file.h tagger/feature.h
tagger/sentence.o: tagger/tagdefines.h tagger/wordtag.h tagger/tagger.h
tagger/sentence.o: tagger/lexicon.h tagger/hashtable.h /usr/include/stdlib.h
tagger/sentence.o: /usr/include/sys/types.h /usr/include/bits/types/clock_t.h
tagger/sentence.o: /usr/include/bits/types/clockid_t.h
tagger/sentence.o: /usr/include/bits/types/time_t.h
tagger/sentence.o: /usr/include/bits/types/timer_t.h
tagger/sentence.o: /usr/include/bits/stdint-intn.h /usr/include/endian.h
tagger/sentence.o: /usr/include/bits/byteswap.h
tagger/sentence.o: /usr/include/bits/uintn-identity.h
tagger/sentence.o: /usr/include/sys/select.h /usr/include/bits/select.h
tagger/sentence.o: /usr/include/bits/types/sigset_t.h
tagger/sentence.o: /usr/include/bits/types/__sigset_t.h
tagger/sentence.o: /usr/include/bits/types/struct_timeval.h
tagger/sentence.o: /usr/include/bits/types/struct_timespec.h
tagger/sentence.o: /usr/include/bits/pthreadtypes.h
tagger/sentence.o: /usr/include/bits/thread-shared-types.h
tagger/sentence.o: /usr/include/bits/pthreadtypes-arch.h
tagger/sentence.o: /usr/include/bits/atomic_wide_counter.h
tagger/sentence.o: /usr/include/bits/struct_mutex.h
tagger/sentence.o: /usr/include/bits/struct_rwlock.h /usr/include/alloca.h
tagger/sentence.o: /usr/include/bits/stdlib-float.h tagger/morflexicon.h
tagger/sentence.o: tagger/hasharray.h tagger/taglexicon.h tagger/tagtrigram.h
tagger/sentence.o: tagger/styleword.h tagger/newwordlexicon.h
tagger/sentence.o: tagger/newword.h tagger/wordlexicon.h
tagger/sentence.o: tagger/inflectlexicon.h tagger/wordruleterms.h
tagger/sentence.o: common/timer.h /usr/include/sys/time.h tagger/text.h
tagger/sentence.o: token/tokenizer.h common/FlexLexer.h
tagger/sentence.o: tagger/trigramgadget.h
tagger/settings.o: common/basics.h /usr/include/stdio.h
tagger/settings.o: /usr/include/bits/libc-header-start.h
tagger/settings.o: /usr/include/features.h /usr/include/features-time64.h
tagger/settings.o: /usr/include/bits/wordsize.h /usr/include/bits/timesize.h
tagger/settings.o: /usr/include/stdc-predef.h /usr/include/sys/cdefs.h
tagger/settings.o: /usr/include/bits/long-double.h /usr/include/gnu/stubs.h
tagger/settings.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
tagger/settings.o: /usr/include/bits/time64.h
tagger/settings.o: /usr/include/bits/types/__fpos_t.h
tagger/settings.o: /usr/include/bits/types/__mbstate_t.h
tagger/settings.o: /usr/include/bits/types/__fpos64_t.h
tagger/settings.o: /usr/include/bits/types/__FILE.h
tagger/settings.o: /usr/include/bits/types/FILE.h
tagger/settings.o: /usr/include/bits/types/struct_FILE.h
tagger/settings.o: /usr/include/bits/types/cookie_io_functions_t.h
tagger/settings.o: /usr/include/bits/stdio_lim.h /usr/include/bits/floatn.h
tagger/settings.o: /usr/include/bits/floatn-common.h common/ensure.h
tagger/settings.o: /usr/include/assert.h common/file.h /usr/include/ctype.h
tagger/settings.o: /usr/include/bits/endian.h /usr/include/bits/endianness.h
tagger/settings.o: /usr/include/bits/types/locale_t.h
tagger/settings.o: /usr/include/bits/types/__locale_t.h common/message.h
tagger/settings.o: tagger/settings.h /usr/include/limits.h
tagger/settings.o: /usr/include/bits/posix1_lim.h
tagger/settings.o: /usr/include/bits/local_lim.h /usr/include/linux/limits.h
tagger/settings.o: /usr/include/bits/pthread_stack_min-dynamic.h
tagger/settings.o: /usr/include/bits/pthread_stack_min.h
tagger/settings.o: /usr/include/bits/posix2_lim.h
tagger/tag.o: common/message.h tagger/tag.h /usr/include/string.h
tagger/tag.o: /usr/include/bits/libc-header-start.h /usr/include/features.h
tagger/tag.o: /usr/include/features-time64.h /usr/include/bits/wordsize.h
tagger/tag.o: /usr/include/bits/timesize.h /usr/include/stdc-predef.h
tagger/tag.o: /usr/include/sys/cdefs.h /usr/include/bits/long-double.h
tagger/tag.o: /usr/include/gnu/stubs.h /usr/include/bits/types/locale_t.h
tagger/tag.o: /usr/include/bits/types/__locale_t.h /usr/include/strings.h
tagger/tag.o: common/basics.h /usr/include/stdio.h /usr/include/bits/types.h
tagger/tag.o: /usr/include/bits/typesizes.h /usr/include/bits/time64.h
tagger/tag.o: /usr/include/bits/types/__fpos_t.h
tagger/tag.o: /usr/include/bits/types/__mbstate_t.h
tagger/tag.o: /usr/include/bits/types/__fpos64_t.h
tagger/tag.o: /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h
tagger/tag.o: /usr/include/bits/types/struct_FILE.h
tagger/tag.o: /usr/include/bits/types/cookie_io_functions_t.h
tagger/tag.o: /usr/include/bits/stdio_lim.h /usr/include/bits/floatn.h
tagger/tag.o: /usr/include/bits/floatn-common.h common/ensure.h
tagger/tag.o: /usr/include/assert.h tagger/bitmap.h common/file.h
tagger/tag.o: /usr/include/ctype.h /usr/include/bits/endian.h
tagger/tag.o: /usr/include/bits/endianness.h tagger/feature.h
tagger/tag.o: tagger/hashscatter.h tagger/settings.h /usr/include/limits.h
tagger/tag.o: /usr/include/bits/posix1_lim.h /usr/include/bits/local_lim.h
tagger/tag.o: /usr/include/linux/limits.h
tagger/tag.o: /usr/include/bits/pthread_stack_min-dynamic.h
tagger/tag.o: /usr/include/bits/pthread_stack_min.h
tagger/tag.o: /usr/include/bits/posix2_lim.h tagger/tagdefines.h
tagger/tag.o: tagger/taglexicon.h tagger/hasharray.h tagger/tagtrigram.h
tagger/tag.o: tagger/token.h tagger/word.h tagger/inflectrule.h
tagger/tag.o: tagger/wordtag.h common/stringbuf.h
tagger/tagger.o: /usr/include/math.h /usr/include/bits/libc-header-start.h
tagger/tagger.o: /usr/include/features.h /usr/include/features-time64.h
tagger/tagger.o: /usr/include/bits/wordsize.h /usr/include/bits/timesize.h
tagger/tagger.o: /usr/include/stdc-predef.h /usr/include/sys/cdefs.h
tagger/tagger.o: /usr/include/bits/long-double.h /usr/include/gnu/stubs.h
tagger/tagger.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
tagger/tagger.o: /usr/include/bits/time64.h /usr/include/bits/math-vector.h
tagger/tagger.o: /usr/include/bits/libm-simd-decl-stubs.h
tagger/tagger.o: /usr/include/bits/floatn.h /usr/include/bits/floatn-common.h
tagger/tagger.o: /usr/include/bits/flt-eval-method.h
tagger/tagger.o: /usr/include/bits/fp-logb.h /usr/include/bits/fp-fast.h
tagger/tagger.o: /usr/include/bits/mathcalls-macros.h
tagger/tagger.o: /usr/include/bits/mathcalls-helper-functions.h
tagger/tagger.o: /usr/include/bits/mathcalls.h
tagger/tagger.o: /usr/include/bits/mathcalls-narrow.h
tagger/tagger.o: /usr/include/bits/iscanonical.h common/file.h
tagger/tagger.o: /usr/include/ctype.h /usr/include/bits/endian.h
tagger/tagger.o: /usr/include/bits/endianness.h
tagger/tagger.o: /usr/include/bits/types/locale_t.h
tagger/tagger.o: /usr/include/bits/types/__locale_t.h common/ensure.h
tagger/tagger.o: /usr/include/assert.h common/message.h tagger/letter.h
tagger/tagger.o: /usr/include/string.h /usr/include/strings.h common/basics.h
tagger/tagger.o: /usr/include/stdio.h /usr/include/bits/types/__fpos_t.h
tagger/tagger.o: /usr/include/bits/types/__mbstate_t.h
tagger/tagger.o: /usr/include/bits/types/__fpos64_t.h
tagger/tagger.o: /usr/include/bits/types/__FILE.h
tagger/tagger.o: /usr/include/bits/types/FILE.h
tagger/tagger.o: /usr/include/bits/types/struct_FILE.h
tagger/tagger.o: /usr/include/bits/types/cookie_io_functions_t.h
tagger/tagger.o: /usr/include/bits/stdio_lim.h tagger/morf.h
tagger/tagger.o: tagger/sentence.h tagger/wordtoken.h tagger/settings.h
tagger/tagger.o: /usr/include/limits.h /usr/include/bits/posix1_lim.h
tagger/tagger.o: /usr/include/bits/local_lim.h /usr/include/linux/limits.h
tagger/tagger.o: /usr/include/bits/pthread_stack_min-dynamic.h
tagger/tagger.o: /usr/include/bits/pthread_stack_min.h
tagger/tagger.o: /usr/include/bits/posix2_lim.h common/stringbuf.h
tagger/tagger.o: tagger/token.h tagger/word.h tagger/hashscatter.h
tagger/tagger.o: tagger/inflectrule.h tagger/tag.h tagger/bitmap.h
tagger/tagger.o: tagger/feature.h tagger/tagdefines.h tagger/wordtag.h
tagger/tagger.o: tagger/tagger.h tagger/lexicon.h tagger/hashtable.h
tagger/tagger.o: /usr/include/stdlib.h /usr/include/sys/types.h
tagger/tagger.o: /usr/include/bits/types/clock_t.h
tagger/tagger.o: /usr/include/bits/types/clockid_t.h
tagger/tagger.o: /usr/include/bits/types/time_t.h
tagger/tagger.o: /usr/include/bits/types/timer_t.h
tagger/tagger.o: /usr/include/bits/stdint-intn.h /usr/include/endian.h
tagger/tagger.o: /usr/include/bits/byteswap.h
tagger/tagger.o: /usr/include/bits/uintn-identity.h /usr/include/sys/select.h
tagger/tagger.o: /usr/include/bits/select.h
tagger/tagger.o: /usr/include/bits/types/sigset_t.h
tagger/tagger.o: /usr/include/bits/types/__sigset_t.h
tagger/tagger.o: /usr/include/bits/types/struct_timeval.h
tagger/tagger.o: /usr/include/bits/types/struct_timespec.h
tagger/tagger.o: /usr/include/bits/pthreadtypes.h
tagger/tagger.o: /usr/include/bits/thread-shared-types.h
tagger/tagger.o: /usr/include/bits/pthreadtypes-arch.h
tagger/tagger.o: /usr/include/bits/atomic_wide_counter.h
tagger/tagger.o: /usr/include/bits/struct_mutex.h
tagger/tagger.o: /usr/include/bits/struct_rwlock.h /usr/include/alloca.h
tagger/tagger.o: /usr/include/bits/stdlib-float.h tagger/morflexicon.h
tagger/tagger.o: tagger/hasharray.h tagger/taglexicon.h tagger/tagtrigram.h
tagger/tagger.o: tagger/styleword.h tagger/newwordlexicon.h tagger/newword.h
tagger/tagger.o: tagger/wordlexicon.h tagger/inflectlexicon.h
tagger/tagger.o: tagger/wordruleterms.h common/timer.h
tagger/tagger.o: /usr/include/sys/time.h tagger/text.h token/tokenizer.h
tagger/tagger.o: common/FlexLexer.h tagger/trigramgadget.h
tagger/taglexicon.o: /usr/include/math.h
tagger/taglexicon.o: /usr/include/bits/libc-header-start.h
tagger/taglexicon.o: /usr/include/features.h /usr/include/features-time64.h
tagger/taglexicon.o: /usr/include/bits/wordsize.h
tagger/taglexicon.o: /usr/include/bits/timesize.h /usr/include/stdc-predef.h
tagger/taglexicon.o: /usr/include/sys/cdefs.h /usr/include/bits/long-double.h
tagger/taglexicon.o: /usr/include/gnu/stubs.h /usr/include/bits/types.h
tagger/taglexicon.o: /usr/include/bits/typesizes.h /usr/include/bits/time64.h
tagger/taglexicon.o: /usr/include/bits/math-vector.h
tagger/taglexicon.o: /usr/include/bits/libm-simd-decl-stubs.h
tagger/taglexicon.o: /usr/include/bits/floatn.h
tagger/taglexicon.o: /usr/include/bits/floatn-common.h
tagger/taglexicon.o: /usr/include/bits/flt-eval-method.h
tagger/taglexicon.o: /usr/include/bits/fp-logb.h /usr/include/bits/fp-fast.h
tagger/taglexicon.o: /usr/include/bits/mathcalls-macros.h
tagger/taglexicon.o: /usr/include/bits/mathcalls-helper-functions.h
tagger/taglexicon.o: /usr/include/bits/mathcalls.h
tagger/taglexicon.o: /usr/include/bits/mathcalls-narrow.h
tagger/taglexicon.o: /usr/include/bits/iscanonical.h /usr/include/string.h
tagger/taglexicon.o: /usr/include/bits/types/locale_t.h
tagger/taglexicon.o: /usr/include/bits/types/__locale_t.h
tagger/taglexicon.o: /usr/include/strings.h /usr/include/stdlib.h
tagger/taglexicon.o: /usr/include/sys/types.h
tagger/taglexicon.o: /usr/include/bits/types/clock_t.h
tagger/taglexicon.o: /usr/include/bits/types/clockid_t.h
tagger/taglexicon.o: /usr/include/bits/types/time_t.h
tagger/taglexicon.o: /usr/include/bits/types/timer_t.h
tagger/taglexicon.o: /usr/include/bits/stdint-intn.h /usr/include/endian.h
tagger/taglexicon.o: /usr/include/bits/endian.h
tagger/taglexicon.o: /usr/include/bits/endianness.h
tagger/taglexicon.o: /usr/include/bits/byteswap.h
tagger/taglexicon.o: /usr/include/bits/uintn-identity.h
tagger/taglexicon.o: /usr/include/sys/select.h /usr/include/bits/select.h
tagger/taglexicon.o: /usr/include/bits/types/sigset_t.h
tagger/taglexicon.o: /usr/include/bits/types/__sigset_t.h
tagger/taglexicon.o: /usr/include/bits/types/struct_timeval.h
tagger/taglexicon.o: /usr/include/bits/types/struct_timespec.h
tagger/taglexicon.o: /usr/include/bits/pthreadtypes.h
tagger/taglexicon.o: /usr/include/bits/thread-shared-types.h
tagger/taglexicon.o: /usr/include/bits/pthreadtypes-arch.h
tagger/taglexicon.o: /usr/include/bits/atomic_wide_counter.h
tagger/taglexicon.o: /usr/include/bits/struct_mutex.h
tagger/taglexicon.o: /usr/include/bits/struct_rwlock.h /usr/include/alloca.h
tagger/taglexicon.o: /usr/include/bits/stdlib-float.h common/file.h
tagger/taglexicon.o: /usr/include/ctype.h common/ensure.h
tagger/taglexicon.o: /usr/include/assert.h common/message.h tagger/letter.h
tagger/taglexicon.o: common/basics.h /usr/include/stdio.h
tagger/taglexicon.o: /usr/include/bits/types/__fpos_t.h
tagger/taglexicon.o: /usr/include/bits/types/__mbstate_t.h
tagger/taglexicon.o: /usr/include/bits/types/__fpos64_t.h
tagger/taglexicon.o: /usr/include/bits/types/__FILE.h
tagger/taglexicon.o: /usr/include/bits/types/FILE.h
tagger/taglexicon.o: /usr/include/bits/types/struct_FILE.h
tagger/taglexicon.o: /usr/include/bits/types/cookie_io_functions_t.h
tagger/taglexicon.o: /usr/include/bits/stdio_lim.h tagger/settings.h
tagger/taglexicon.o: /usr/include/limits.h /usr/include/bits/posix1_lim.h
tagger/taglexicon.o: /usr/include/bits/local_lim.h
tagger/taglexicon.o: /usr/include/linux/limits.h
tagger/taglexicon.o: /usr/include/bits/pthread_stack_min-dynamic.h
tagger/taglexicon.o: /usr/include/bits/pthread_stack_min.h
tagger/taglexicon.o: /usr/include/bits/posix2_lim.h tagger/taglexicon.h
tagger/taglexicon.o: tagger/bitmap.h tagger/feature.h tagger/hasharray.h
tagger/taglexicon.o: tagger/tag.h tagger/hashscatter.h tagger/tagdefines.h
tagger/taglexicon.o: tagger/tagtrigram.h tagger/token.h tagger/word.h
tagger/taglexicon.o: tagger/inflectrule.h tagger/wordtag.h common/stringbuf.h
tagger/text.o: tagger/sentence.h tagger/wordtoken.h tagger/letter.h
tagger/text.o: /usr/include/string.h /usr/include/bits/libc-header-start.h
tagger/text.o: /usr/include/features.h /usr/include/features-time64.h
tagger/text.o: /usr/include/bits/wordsize.h /usr/include/bits/timesize.h
tagger/text.o: /usr/include/stdc-predef.h /usr/include/sys/cdefs.h
tagger/text.o: /usr/include/bits/long-double.h /usr/include/gnu/stubs.h
tagger/text.o: /usr/include/bits/types/locale_t.h
tagger/text.o: /usr/include/bits/types/__locale_t.h /usr/include/strings.h
tagger/text.o: /usr/include/ctype.h /usr/include/bits/types.h
tagger/text.o: /usr/include/bits/typesizes.h /usr/include/bits/time64.h
tagger/text.o: /usr/include/bits/endian.h /usr/include/bits/endianness.h
tagger/text.o: common/basics.h /usr/include/stdio.h
tagger/text.o: /usr/include/bits/types/__fpos_t.h
tagger/text.o: /usr/include/bits/types/__mbstate_t.h
tagger/text.o: /usr/include/bits/types/__fpos64_t.h
tagger/text.o: /usr/include/bits/types/__FILE.h
tagger/text.o: /usr/include/bits/types/FILE.h
tagger/text.o: /usr/include/bits/types/struct_FILE.h
tagger/text.o: /usr/include/bits/types/cookie_io_functions_t.h
tagger/text.o: /usr/include/bits/stdio_lim.h /usr/include/bits/floatn.h
tagger/text.o: /usr/include/bits/floatn-common.h common/ensure.h
tagger/text.o: /usr/include/assert.h tagger/settings.h /usr/include/limits.h
tagger/text.o: /usr/include/bits/posix1_lim.h /usr/include/bits/local_lim.h
tagger/text.o: /usr/include/linux/limits.h
tagger/text.o: /usr/include/bits/pthread_stack_min-dynamic.h
tagger/text.o: /usr/include/bits/pthread_stack_min.h
tagger/text.o: /usr/include/bits/posix2_lim.h common/stringbuf.h
tagger/text.o: tagger/token.h tagger/word.h tagger/hashscatter.h
tagger/text.o: tagger/inflectrule.h common/message.h tagger/tag.h
tagger/text.o: tagger/bitmap.h common/file.h tagger/feature.h
tagger/text.o: tagger/tagdefines.h tagger/wordtag.h tagger/text.h
tagger/word.o: /usr/include/math.h /usr/include/bits/libc-header-start.h
tagger/word.o: /usr/include/features.h /usr/include/features-time64.h
tagger/word.o: /usr/include/bits/wordsize.h /usr/include/bits/timesize.h
tagger/word.o: /usr/include/stdc-predef.h /usr/include/sys/cdefs.h
tagger/word.o: /usr/include/bits/long-double.h /usr/include/gnu/stubs.h
tagger/word.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
tagger/word.o: /usr/include/bits/time64.h /usr/include/bits/math-vector.h
tagger/word.o: /usr/include/bits/libm-simd-decl-stubs.h
tagger/word.o: /usr/include/bits/floatn.h /usr/include/bits/floatn-common.h
tagger/word.o: /usr/include/bits/flt-eval-method.h
tagger/word.o: /usr/include/bits/fp-logb.h /usr/include/bits/fp-fast.h
tagger/word.o: /usr/include/bits/mathcalls-macros.h
tagger/word.o: /usr/include/bits/mathcalls-helper-functions.h
tagger/word.o: /usr/include/bits/mathcalls.h
tagger/word.o: /usr/include/bits/mathcalls-narrow.h
tagger/word.o: /usr/include/bits/iscanonical.h tagger/word.h
tagger/word.o: /usr/include/string.h /usr/include/bits/types/locale_t.h
tagger/word.o: /usr/include/bits/types/__locale_t.h /usr/include/strings.h
tagger/word.o: tagger/hashscatter.h tagger/inflectrule.h common/basics.h
tagger/word.o: /usr/include/stdio.h /usr/include/bits/types/__fpos_t.h
tagger/word.o: /usr/include/bits/types/__mbstate_t.h
tagger/word.o: /usr/include/bits/types/__fpos64_t.h
tagger/word.o: /usr/include/bits/types/__FILE.h
tagger/word.o: /usr/include/bits/types/FILE.h
tagger/word.o: /usr/include/bits/types/struct_FILE.h
tagger/word.o: /usr/include/bits/types/cookie_io_functions_t.h
tagger/word.o: /usr/include/bits/stdio_lim.h common/ensure.h
tagger/word.o: /usr/include/assert.h /usr/include/limits.h
tagger/word.o: /usr/include/bits/posix1_lim.h /usr/include/bits/local_lim.h
tagger/word.o: /usr/include/linux/limits.h
tagger/word.o: /usr/include/bits/pthread_stack_min-dynamic.h
tagger/word.o: /usr/include/bits/pthread_stack_min.h
tagger/word.o: /usr/include/bits/posix2_lim.h common/message.h tagger/tag.h
tagger/word.o: tagger/bitmap.h common/file.h /usr/include/ctype.h
tagger/word.o: /usr/include/bits/endian.h /usr/include/bits/endianness.h
tagger/word.o: tagger/feature.h tagger/settings.h tagger/tagdefines.h
tagger/word.o: tagger/wordtag.h common/stringbuf.h tagger/newword.h
tagger/wordlexicon.o: common/file.h /usr/include/ctype.h
tagger/wordlexicon.o: /usr/include/features.h /usr/include/features-time64.h
tagger/wordlexicon.o: /usr/include/bits/wordsize.h
tagger/wordlexicon.o: /usr/include/bits/timesize.h /usr/include/stdc-predef.h
tagger/wordlexicon.o: /usr/include/sys/cdefs.h
tagger/wordlexicon.o: /usr/include/bits/long-double.h
tagger/wordlexicon.o: /usr/include/gnu/stubs.h /usr/include/bits/types.h
tagger/wordlexicon.o: /usr/include/bits/typesizes.h
tagger/wordlexicon.o: /usr/include/bits/time64.h /usr/include/bits/endian.h
tagger/wordlexicon.o: /usr/include/bits/endianness.h
tagger/wordlexicon.o: /usr/include/bits/types/locale_t.h
tagger/wordlexicon.o: /usr/include/bits/types/__locale_t.h common/ensure.h
tagger/wordlexicon.o: /usr/include/assert.h common/message.h tagger/letter.h
tagger/wordlexicon.o: /usr/include/string.h
tagger/wordlexicon.o: /usr/include/bits/libc-header-start.h
tagger/wordlexicon.o: /usr/include/strings.h common/basics.h
tagger/wordlexicon.o: /usr/include/stdio.h /usr/include/bits/types/__fpos_t.h
tagger/wordlexicon.o: /usr/include/bits/types/__mbstate_t.h
tagger/wordlexicon.o: /usr/include/bits/types/__fpos64_t.h
tagger/wordlexicon.o: /usr/include/bits/types/__FILE.h
tagger/wordlexicon.o: /usr/include/bits/types/FILE.h
tagger/wordlexicon.o: /usr/include/bits/types/struct_FILE.h
tagger/wordlexicon.o: /usr/include/bits/types/cookie_io_functions_t.h
tagger/wordlexicon.o: /usr/include/bits/stdio_lim.h
tagger/wordlexicon.o: /usr/include/bits/floatn.h
tagger/wordlexicon.o: /usr/include/bits/floatn-common.h
tagger/wordlexicon.o: tagger/newwordlexicon.h tagger/newword.h tagger/word.h
tagger/wordlexicon.o: tagger/hashscatter.h tagger/inflectrule.h
tagger/wordlexicon.o: /usr/include/limits.h /usr/include/bits/posix1_lim.h
tagger/wordlexicon.o: /usr/include/bits/local_lim.h
tagger/wordlexicon.o: /usr/include/linux/limits.h
tagger/wordlexicon.o: /usr/include/bits/pthread_stack_min-dynamic.h
tagger/wordlexicon.o: /usr/include/bits/pthread_stack_min.h
tagger/wordlexicon.o: /usr/include/bits/posix2_lim.h tagger/tag.h
tagger/wordlexicon.o: tagger/bitmap.h tagger/feature.h tagger/settings.h
tagger/wordlexicon.o: tagger/tagdefines.h tagger/wordtag.h common/stringbuf.h
tagger/wordlexicon.o: tagger/hashtable.h /usr/include/stdlib.h
tagger/wordlexicon.o: /usr/include/sys/types.h
tagger/wordlexicon.o: /usr/include/bits/types/clock_t.h
tagger/wordlexicon.o: /usr/include/bits/types/clockid_t.h
tagger/wordlexicon.o: /usr/include/bits/types/time_t.h
tagger/wordlexicon.o: /usr/include/bits/types/timer_t.h
tagger/wordlexicon.o: /usr/include/bits/stdint-intn.h /usr/include/endian.h
tagger/wordlexicon.o: /usr/include/bits/byteswap.h
tagger/wordlexicon.o: /usr/include/bits/uintn-identity.h
tagger/wordlexicon.o: /usr/include/sys/select.h /usr/include/bits/select.h
tagger/wordlexicon.o: /usr/include/bits/types/sigset_t.h
tagger/wordlexicon.o: /usr/include/bits/types/__sigset_t.h
tagger/wordlexicon.o: /usr/include/bits/types/struct_timeval.h
tagger/wordlexicon.o: /usr/include/bits/types/struct_timespec.h
tagger/wordlexicon.o: /usr/include/bits/pthreadtypes.h
tagger/wordlexicon.o: /usr/include/bits/thread-shared-types.h
tagger/wordlexicon.o: /usr/include/bits/pthreadtypes-arch.h
tagger/wordlexicon.o: /usr/include/bits/atomic_wide_counter.h
tagger/wordlexicon.o: /usr/include/bits/struct_mutex.h
tagger/wordlexicon.o: /usr/include/bits/struct_rwlock.h /usr/include/alloca.h
tagger/wordlexicon.o: /usr/include/bits/stdlib-float.h tagger/wordlexicon.h
tagger/wordlexicon.o: tagger/hasharray.h tagger/inflectlexicon.h
tagger/wordlexicon.o: tagger/taglexicon.h tagger/tagtrigram.h tagger/token.h
tagger/wordlexicon.o: tagger/styleword.h
tagger/wordtag.o: tagger/word.h /usr/include/string.h
tagger/wordtag.o: /usr/include/bits/libc-header-start.h
tagger/wordtag.o: /usr/include/features.h /usr/include/features-time64.h
tagger/wordtag.o: /usr/include/bits/wordsize.h /usr/include/bits/timesize.h
tagger/wordtag.o: /usr/include/stdc-predef.h /usr/include/sys/cdefs.h
tagger/wordtag.o: /usr/include/bits/long-double.h /usr/include/gnu/stubs.h
tagger/wordtag.o: /usr/include/bits/types/locale_t.h
tagger/wordtag.o: /usr/include/bits/types/__locale_t.h /usr/include/strings.h
tagger/wordtag.o: tagger/hashscatter.h tagger/inflectrule.h common/basics.h
tagger/wordtag.o: /usr/include/stdio.h /usr/include/bits/types.h
tagger/wordtag.o: /usr/include/bits/typesizes.h /usr/include/bits/time64.h
tagger/wordtag.o: /usr/include/bits/types/__fpos_t.h
tagger/wordtag.o: /usr/include/bits/types/__mbstate_t.h
tagger/wordtag.o: /usr/include/bits/types/__fpos64_t.h
tagger/wordtag.o: /usr/include/bits/types/__FILE.h
tagger/wordtag.o: /usr/include/bits/types/FILE.h
tagger/wordtag.o: /usr/include/bits/types/struct_FILE.h
tagger/wordtag.o: /usr/include/bits/types/cookie_io_functions_t.h
tagger/wordtag.o: /usr/include/bits/stdio_lim.h /usr/include/bits/floatn.h
tagger/wordtag.o: /usr/include/bits/floatn-common.h common/ensure.h
tagger/wordtag.o: /usr/include/assert.h /usr/include/limits.h
tagger/wordtag.o: /usr/include/bits/posix1_lim.h
tagger/wordtag.o: /usr/include/bits/local_lim.h /usr/include/linux/limits.h
tagger/wordtag.o: /usr/include/bits/pthread_stack_min-dynamic.h
tagger/wordtag.o: /usr/include/bits/pthread_stack_min.h
tagger/wordtag.o: /usr/include/bits/posix2_lim.h common/message.h
tagger/wordtag.o: tagger/tag.h tagger/bitmap.h common/file.h
tagger/wordtag.o: /usr/include/ctype.h /usr/include/bits/endian.h
tagger/wordtag.o: /usr/include/bits/endianness.h tagger/feature.h
tagger/wordtag.o: tagger/settings.h tagger/tagdefines.h tagger/wordtag.h
tagger/wordtag.o: common/stringbuf.h tagger/wordlexicon.h tagger/newword.h
tagger/wordtag.o: tagger/hasharray.h tagger/inflectlexicon.h
tagger/wordtag.o: tagger/taglexicon.h tagger/tagtrigram.h tagger/token.h
tagger/wordtag.o: tagger/styleword.h
tagger/wordtoken.o: tagger/letter.h /usr/include/string.h
tagger/wordtoken.o: /usr/include/bits/libc-header-start.h
tagger/wordtoken.o: /usr/include/features.h /usr/include/features-time64.h
tagger/wordtoken.o: /usr/include/bits/wordsize.h /usr/include/bits/timesize.h
tagger/wordtoken.o: /usr/include/stdc-predef.h /usr/include/sys/cdefs.h
tagger/wordtoken.o: /usr/include/bits/long-double.h /usr/include/gnu/stubs.h
tagger/wordtoken.o: /usr/include/bits/types/locale_t.h
tagger/wordtoken.o: /usr/include/bits/types/__locale_t.h
tagger/wordtoken.o: /usr/include/strings.h /usr/include/ctype.h
tagger/wordtoken.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
tagger/wordtoken.o: /usr/include/bits/time64.h /usr/include/bits/endian.h
tagger/wordtoken.o: /usr/include/bits/endianness.h common/basics.h
tagger/wordtoken.o: /usr/include/stdio.h /usr/include/bits/types/__fpos_t.h
tagger/wordtoken.o: /usr/include/bits/types/__mbstate_t.h
tagger/wordtoken.o: /usr/include/bits/types/__fpos64_t.h
tagger/wordtoken.o: /usr/include/bits/types/__FILE.h
tagger/wordtoken.o: /usr/include/bits/types/FILE.h
tagger/wordtoken.o: /usr/include/bits/types/struct_FILE.h
tagger/wordtoken.o: /usr/include/bits/types/cookie_io_functions_t.h
tagger/wordtoken.o: /usr/include/bits/stdio_lim.h /usr/include/bits/floatn.h
tagger/wordtoken.o: /usr/include/bits/floatn-common.h common/ensure.h
tagger/wordtoken.o: /usr/include/assert.h tagger/settings.h
tagger/wordtoken.o: /usr/include/limits.h /usr/include/bits/posix1_lim.h
tagger/wordtoken.o: /usr/include/bits/local_lim.h /usr/include/linux/limits.h
tagger/wordtoken.o: /usr/include/bits/pthread_stack_min-dynamic.h
tagger/wordtoken.o: /usr/include/bits/pthread_stack_min.h
tagger/wordtoken.o: /usr/include/bits/posix2_lim.h tagger/token.h
tagger/wordtoken.o: tagger/newword.h tagger/word.h tagger/hashscatter.h
tagger/wordtoken.o: tagger/inflectrule.h common/message.h tagger/tag.h
tagger/wordtoken.o: tagger/bitmap.h common/file.h tagger/feature.h
tagger/wordtoken.o: tagger/tagdefines.h tagger/wordtag.h common/stringbuf.h
tagger/wordtoken.o: tagger/wordtoken.h
token/tokenizer.o: common/FlexLexer.h tagger/token.h /usr/include/string.h
token/tokenizer.o: /usr/include/bits/libc-header-start.h
token/tokenizer.o: /usr/include/features.h /usr/include/features-time64.h
token/tokenizer.o: /usr/include/bits/wordsize.h /usr/include/bits/timesize.h
token/tokenizer.o: /usr/include/stdc-predef.h /usr/include/sys/cdefs.h
token/tokenizer.o: /usr/include/bits/long-double.h /usr/include/gnu/stubs.h
token/tokenizer.o: /usr/include/bits/types/locale_t.h
token/tokenizer.o: /usr/include/bits/types/__locale_t.h
token/tokenizer.o: /usr/include/strings.h /usr/include/stdlib.h
token/tokenizer.o: /usr/include/bits/floatn.h
token/tokenizer.o: /usr/include/bits/floatn-common.h /usr/include/sys/types.h
token/tokenizer.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
token/tokenizer.o: /usr/include/bits/time64.h
token/tokenizer.o: /usr/include/bits/types/clock_t.h
token/tokenizer.o: /usr/include/bits/types/clockid_t.h
token/tokenizer.o: /usr/include/bits/types/time_t.h
token/tokenizer.o: /usr/include/bits/types/timer_t.h
token/tokenizer.o: /usr/include/bits/stdint-intn.h /usr/include/endian.h
token/tokenizer.o: /usr/include/bits/endian.h /usr/include/bits/endianness.h
token/tokenizer.o: /usr/include/bits/byteswap.h
token/tokenizer.o: /usr/include/bits/uintn-identity.h
token/tokenizer.o: /usr/include/sys/select.h /usr/include/bits/select.h
token/tokenizer.o: /usr/include/bits/types/sigset_t.h
token/tokenizer.o: /usr/include/bits/types/__sigset_t.h
token/tokenizer.o: /usr/include/bits/types/struct_timeval.h
token/tokenizer.o: /usr/include/bits/types/struct_timespec.h
token/tokenizer.o: /usr/include/bits/pthreadtypes.h
token/tokenizer.o: /usr/include/bits/thread-shared-types.h
token/tokenizer.o: /usr/include/bits/pthreadtypes-arch.h
token/tokenizer.o: /usr/include/bits/atomic_wide_counter.h
token/tokenizer.o: /usr/include/bits/struct_mutex.h
token/tokenizer.o: /usr/include/bits/struct_rwlock.h /usr/include/alloca.h
token/tokenizer.o: /usr/include/bits/stdlib-float.h
cgigranska/wwwscrutinizer.o: /usr/include/stdio.h
cgigranska/wwwscrutinizer.o: /usr/include/bits/libc-header-start.h
cgigranska/wwwscrutinizer.o: /usr/include/features.h
cgigranska/wwwscrutinizer.o: /usr/include/features-time64.h
cgigranska/wwwscrutinizer.o: /usr/include/bits/wordsize.h
cgigranska/wwwscrutinizer.o: /usr/include/bits/timesize.h
cgigranska/wwwscrutinizer.o: /usr/include/stdc-predef.h
cgigranska/wwwscrutinizer.o: /usr/include/sys/cdefs.h
cgigranska/wwwscrutinizer.o: /usr/include/bits/long-double.h
cgigranska/wwwscrutinizer.o: /usr/include/gnu/stubs.h
cgigranska/wwwscrutinizer.o: /usr/include/bits/types.h
cgigranska/wwwscrutinizer.o: /usr/include/bits/typesizes.h
cgigranska/wwwscrutinizer.o: /usr/include/bits/time64.h
cgigranska/wwwscrutinizer.o: /usr/include/bits/types/__fpos_t.h
cgigranska/wwwscrutinizer.o: /usr/include/bits/types/__mbstate_t.h
cgigranska/wwwscrutinizer.o: /usr/include/bits/types/__fpos64_t.h
cgigranska/wwwscrutinizer.o: /usr/include/bits/types/__FILE.h
cgigranska/wwwscrutinizer.o: /usr/include/bits/types/FILE.h
cgigranska/wwwscrutinizer.o: /usr/include/bits/types/struct_FILE.h
cgigranska/wwwscrutinizer.o: /usr/include/bits/types/cookie_io_functions_t.h
cgigranska/wwwscrutinizer.o: /usr/include/bits/stdio_lim.h
cgigranska/wwwscrutinizer.o: /usr/include/bits/floatn.h
cgigranska/wwwscrutinizer.o: /usr/include/bits/floatn-common.h
cgigranska/wwwscrutinizer.o: /usr/include/stdlib.h /usr/include/sys/types.h
cgigranska/wwwscrutinizer.o: /usr/include/bits/types/clock_t.h
cgigranska/wwwscrutinizer.o: /usr/include/bits/types/clockid_t.h
cgigranska/wwwscrutinizer.o: /usr/include/bits/types/time_t.h
cgigranska/wwwscrutinizer.o: /usr/include/bits/types/timer_t.h
cgigranska/wwwscrutinizer.o: /usr/include/bits/stdint-intn.h
cgigranska/wwwscrutinizer.o: /usr/include/endian.h /usr/include/bits/endian.h
cgigranska/wwwscrutinizer.o: /usr/include/bits/endianness.h
cgigranska/wwwscrutinizer.o: /usr/include/bits/byteswap.h
cgigranska/wwwscrutinizer.o: /usr/include/bits/uintn-identity.h
cgigranska/wwwscrutinizer.o: /usr/include/sys/select.h
cgigranska/wwwscrutinizer.o: /usr/include/bits/select.h
cgigranska/wwwscrutinizer.o: /usr/include/bits/types/sigset_t.h
cgigranska/wwwscrutinizer.o: /usr/include/bits/types/__sigset_t.h
cgigranska/wwwscrutinizer.o: /usr/include/bits/types/struct_timeval.h
cgigranska/wwwscrutinizer.o: /usr/include/bits/types/struct_timespec.h
cgigranska/wwwscrutinizer.o: /usr/include/bits/pthreadtypes.h
cgigranska/wwwscrutinizer.o: /usr/include/bits/thread-shared-types.h
cgigranska/wwwscrutinizer.o: /usr/include/bits/pthreadtypes-arch.h
cgigranska/wwwscrutinizer.o: /usr/include/bits/atomic_wide_counter.h
cgigranska/wwwscrutinizer.o: /usr/include/bits/struct_mutex.h
cgigranska/wwwscrutinizer.o: /usr/include/bits/struct_rwlock.h
cgigranska/wwwscrutinizer.o: /usr/include/alloca.h
cgigranska/wwwscrutinizer.o: /usr/include/bits/stdlib-float.h
cgigranska/wwwscrutinizer.o: /usr/include/string.h
cgigranska/wwwscrutinizer.o: /usr/include/bits/types/locale_t.h
cgigranska/wwwscrutinizer.o: /usr/include/bits/types/__locale_t.h
cgigranska/wwwscrutinizer.o: /usr/include/strings.h /usr/include/time.h
cgigranska/wwwscrutinizer.o: /usr/include/bits/time.h
cgigranska/wwwscrutinizer.o: /usr/include/bits/types/struct_tm.h
cgigranska/wwwscrutinizer.o: /usr/include/bits/types/struct_itimerspec.h
cgigranska/wwwscrutinizer.o: /usr/include/sys/timeb.h
cgigranska/wwwscrutinizer.o: /usr/include/bits/types/struct_timeb.h
cgigranska/wwwscrutinizer.o: /usr/include/unistd.h
cgigranska/wwwscrutinizer.o: /usr/include/bits/posix_opt.h
cgigranska/wwwscrutinizer.o: /usr/include/bits/environments.h
cgigranska/wwwscrutinizer.o: /usr/include/bits/confname.h
cgigranska/wwwscrutinizer.o: /usr/include/bits/getopt_posix.h
cgigranska/wwwscrutinizer.o: /usr/include/bits/getopt_core.h
cgigranska/wwwscrutinizer.o: /usr/include/bits/unistd_ext.h
cgigranska/wwwscrutinizer.o: /usr/include/sys/wait.h /usr/include/signal.h
cgigranska/wwwscrutinizer.o: /usr/include/bits/signum-generic.h
cgigranska/wwwscrutinizer.o: /usr/include/bits/signum-arch.h
cgigranska/wwwscrutinizer.o: /usr/include/bits/types/sig_atomic_t.h
cgigranska/wwwscrutinizer.o: /usr/include/bits/types/siginfo_t.h
cgigranska/wwwscrutinizer.o: /usr/include/bits/types/__sigval_t.h
cgigranska/wwwscrutinizer.o: /usr/include/bits/siginfo-arch.h
cgigranska/wwwscrutinizer.o: /usr/include/bits/siginfo-consts.h
cgigranska/wwwscrutinizer.o: /usr/include/bits/types/sigval_t.h
cgigranska/wwwscrutinizer.o: /usr/include/bits/types/sigevent_t.h
cgigranska/wwwscrutinizer.o: /usr/include/bits/sigevent-consts.h
cgigranska/wwwscrutinizer.o: /usr/include/bits/sigaction.h
cgigranska/wwwscrutinizer.o: /usr/include/bits/sigcontext.h
cgigranska/wwwscrutinizer.o: /usr/include/bits/types/stack_t.h
cgigranska/wwwscrutinizer.o: /usr/include/sys/ucontext.h
cgigranska/wwwscrutinizer.o: /usr/include/bits/sigstack.h
cgigranska/wwwscrutinizer.o: /usr/include/bits/sigstksz.h
cgigranska/wwwscrutinizer.o: /usr/include/bits/ss_flags.h
cgigranska/wwwscrutinizer.o: /usr/include/bits/types/struct_sigstack.h
cgigranska/wwwscrutinizer.o: /usr/include/bits/sigthread.h
cgigranska/wwwscrutinizer.o: /usr/include/bits/signal_ext.h
cgigranska/wwwscrutinizer.o: /usr/include/bits/waitflags.h
cgigranska/wwwscrutinizer.o: /usr/include/bits/waitstatus.h
cgigranska/wwwscrutinizer.o: /usr/include/bits/types/idtype_t.h
cgigranska/wwwscrutinizer.o: /usr/include/errno.h /usr/include/bits/errno.h
cgigranska/wwwscrutinizer.o: /usr/include/linux/errno.h
cgigranska/wwwscrutinizer.o: /usr/include/asm/errno.h
cgigranska/wwwscrutinizer.o: /usr/include/asm-generic/errno.h
cgigranska/wwwscrutinizer.o: /usr/include/asm-generic/errno-base.h
cgigranska/wwwscrutinizer.o: /usr/include/ctype.h
stava/rattstava.o: /usr/include/stdio.h /usr/include/bits/libc-header-start.h
stava/rattstava.o: /usr/include/features.h /usr/include/features-time64.h
stava/rattstava.o: /usr/include/bits/wordsize.h /usr/include/bits/timesize.h
stava/rattstava.o: /usr/include/stdc-predef.h /usr/include/sys/cdefs.h
stava/rattstava.o: /usr/include/bits/long-double.h /usr/include/gnu/stubs.h
stava/rattstava.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
stava/rattstava.o: /usr/include/bits/time64.h
stava/rattstava.o: /usr/include/bits/types/__fpos_t.h
stava/rattstava.o: /usr/include/bits/types/__mbstate_t.h
stava/rattstava.o: /usr/include/bits/types/__fpos64_t.h
stava/rattstava.o: /usr/include/bits/types/__FILE.h
stava/rattstava.o: /usr/include/bits/types/FILE.h
stava/rattstava.o: /usr/include/bits/types/struct_FILE.h
stava/rattstava.o: /usr/include/bits/types/cookie_io_functions_t.h
stava/rattstava.o: /usr/include/bits/stdio_lim.h /usr/include/bits/floatn.h
stava/rattstava.o: /usr/include/bits/floatn-common.h /usr/include/stdlib.h
stava/rattstava.o: /usr/include/sys/types.h /usr/include/bits/types/clock_t.h
stava/rattstava.o: /usr/include/bits/types/clockid_t.h
stava/rattstava.o: /usr/include/bits/types/time_t.h
stava/rattstava.o: /usr/include/bits/types/timer_t.h
stava/rattstava.o: /usr/include/bits/stdint-intn.h /usr/include/endian.h
stava/rattstava.o: /usr/include/bits/endian.h /usr/include/bits/endianness.h
stava/rattstava.o: /usr/include/bits/byteswap.h
stava/rattstava.o: /usr/include/bits/uintn-identity.h
stava/rattstava.o: /usr/include/sys/select.h /usr/include/bits/select.h
stava/rattstava.o: /usr/include/bits/types/sigset_t.h
stava/rattstava.o: /usr/include/bits/types/__sigset_t.h
stava/rattstava.o: /usr/include/bits/types/struct_timeval.h
stava/rattstava.o: /usr/include/bits/types/struct_timespec.h
stava/rattstava.o: /usr/include/bits/pthreadtypes.h
stava/rattstava.o: /usr/include/bits/thread-shared-types.h
stava/rattstava.o: /usr/include/bits/pthreadtypes-arch.h
stava/rattstava.o: /usr/include/bits/atomic_wide_counter.h
stava/rattstava.o: /usr/include/bits/struct_mutex.h
stava/rattstava.o: /usr/include/bits/struct_rwlock.h /usr/include/alloca.h
stava/rattstava.o: /usr/include/bits/stdlib-float.h /usr/include/string.h
stava/rattstava.o: /usr/include/bits/types/locale_t.h
stava/rattstava.o: /usr/include/bits/types/__locale_t.h
stava/rattstava.o: /usr/include/strings.h stava/stava.h stava/rattstava.h
stava/rattstava.o: stava/suffix.h
stava/stavaapi.o: /usr/include/stdio.h /usr/include/bits/libc-header-start.h
stava/stavaapi.o: /usr/include/features.h /usr/include/features-time64.h
stava/stavaapi.o: /usr/include/bits/wordsize.h /usr/include/bits/timesize.h
stava/stavaapi.o: /usr/include/stdc-predef.h /usr/include/sys/cdefs.h
stava/stavaapi.o: /usr/include/bits/long-double.h /usr/include/gnu/stubs.h
stava/stavaapi.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
stava/stavaapi.o: /usr/include/bits/time64.h
stava/stavaapi.o: /usr/include/bits/types/__fpos_t.h
stava/stavaapi.o: /usr/include/bits/types/__mbstate_t.h
stava/stavaapi.o: /usr/include/bits/types/__fpos64_t.h
stava/stavaapi.o: /usr/include/bits/types/__FILE.h
stava/stavaapi.o: /usr/include/bits/types/FILE.h
stava/stavaapi.o: /usr/include/bits/types/struct_FILE.h
stava/stavaapi.o: /usr/include/bits/types/cookie_io_functions_t.h
stava/stavaapi.o: /usr/include/bits/stdio_lim.h /usr/include/bits/floatn.h
stava/stavaapi.o: /usr/include/bits/floatn-common.h /usr/include/stdlib.h
stava/stavaapi.o: /usr/include/sys/types.h /usr/include/bits/types/clock_t.h
stava/stavaapi.o: /usr/include/bits/types/clockid_t.h
stava/stavaapi.o: /usr/include/bits/types/time_t.h
stava/stavaapi.o: /usr/include/bits/types/timer_t.h
stava/stavaapi.o: /usr/include/bits/stdint-intn.h /usr/include/endian.h
stava/stavaapi.o: /usr/include/bits/endian.h /usr/include/bits/endianness.h
stava/stavaapi.o: /usr/include/bits/byteswap.h
stava/stavaapi.o: /usr/include/bits/uintn-identity.h
stava/stavaapi.o: /usr/include/sys/select.h /usr/include/bits/select.h
stava/stavaapi.o: /usr/include/bits/types/sigset_t.h
stava/stavaapi.o: /usr/include/bits/types/__sigset_t.h
stava/stavaapi.o: /usr/include/bits/types/struct_timeval.h
stava/stavaapi.o: /usr/include/bits/types/struct_timespec.h
stava/stavaapi.o: /usr/include/bits/pthreadtypes.h
stava/stavaapi.o: /usr/include/bits/thread-shared-types.h
stava/stavaapi.o: /usr/include/bits/pthreadtypes-arch.h
stava/stavaapi.o: /usr/include/bits/atomic_wide_counter.h
stava/stavaapi.o: /usr/include/bits/struct_mutex.h
stava/stavaapi.o: /usr/include/bits/struct_rwlock.h /usr/include/alloca.h
stava/stavaapi.o: /usr/include/bits/stdlib-float.h /usr/include/string.h
stava/stavaapi.o: /usr/include/bits/types/locale_t.h
stava/stavaapi.o: /usr/include/bits/types/__locale_t.h /usr/include/strings.h
stava/stavaapi.o: /usr/include/ctype.h stava/stava.h stava/rattstava.h
stava/stavaapi.o: stava/suffix.h stava/stavaconstants.h stava/stavaapi.h
stava/suffix.o: stava/suffix.h stava/stava.h /usr/include/stdio.h
stava/suffix.o: /usr/include/bits/libc-header-start.h /usr/include/features.h
stava/suffix.o: /usr/include/features-time64.h /usr/include/bits/wordsize.h
stava/suffix.o: /usr/include/bits/timesize.h /usr/include/stdc-predef.h
stava/suffix.o: /usr/include/sys/cdefs.h /usr/include/bits/long-double.h
stava/suffix.o: /usr/include/gnu/stubs.h /usr/include/bits/types.h
stava/suffix.o: /usr/include/bits/typesizes.h /usr/include/bits/time64.h
stava/suffix.o: /usr/include/bits/types/__fpos_t.h
stava/suffix.o: /usr/include/bits/types/__mbstate_t.h
stava/suffix.o: /usr/include/bits/types/__fpos64_t.h
stava/suffix.o: /usr/include/bits/types/__FILE.h
stava/suffix.o: /usr/include/bits/types/FILE.h
stava/suffix.o: /usr/include/bits/types/struct_FILE.h
stava/suffix.o: /usr/include/bits/types/cookie_io_functions_t.h
stava/suffix.o: /usr/include/bits/stdio_lim.h /usr/include/bits/floatn.h
stava/suffix.o: /usr/include/bits/floatn-common.h /usr/include/stdlib.h
stava/suffix.o: /usr/include/sys/types.h /usr/include/bits/types/clock_t.h
stava/suffix.o: /usr/include/bits/types/clockid_t.h
stava/suffix.o: /usr/include/bits/types/time_t.h
stava/suffix.o: /usr/include/bits/types/timer_t.h
stava/suffix.o: /usr/include/bits/stdint-intn.h /usr/include/endian.h
stava/suffix.o: /usr/include/bits/endian.h /usr/include/bits/endianness.h
stava/suffix.o: /usr/include/bits/byteswap.h
stava/suffix.o: /usr/include/bits/uintn-identity.h /usr/include/sys/select.h
stava/suffix.o: /usr/include/bits/select.h /usr/include/bits/types/sigset_t.h
stava/suffix.o: /usr/include/bits/types/__sigset_t.h
stava/suffix.o: /usr/include/bits/types/struct_timeval.h
stava/suffix.o: /usr/include/bits/types/struct_timespec.h
stava/suffix.o: /usr/include/bits/pthreadtypes.h
stava/suffix.o: /usr/include/bits/thread-shared-types.h
stava/suffix.o: /usr/include/bits/pthreadtypes-arch.h
stava/suffix.o: /usr/include/bits/atomic_wide_counter.h
stava/suffix.o: /usr/include/bits/struct_mutex.h
stava/suffix.o: /usr/include/bits/struct_rwlock.h /usr/include/alloca.h
stava/suffix.o: /usr/include/bits/stdlib-float.h /usr/include/string.h
stava/suffix.o: /usr/include/bits/types/locale_t.h
stava/suffix.o: /usr/include/bits/types/__locale_t.h /usr/include/strings.h
