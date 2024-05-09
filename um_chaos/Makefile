SRCS = $(wildcard src/*.cpp) $(wildcard src/effects/*.cpp)
OBJS = $(patsubst src/%.cpp,build/%.obj,$(SRCS))

FXCS = $(patsubst src/%.hlsl,th18/%.fxc,$(wildcard src/*.hlsl))

ECLS = $(patsubst src/%.tecl,th18/%.ecl,$(wildcard src/*.tecl))
ANMS = $(patsubst src/%.tanm,th18/%.anm,$(wildcard src/*.tanm))

DEPDIR := build/.deps
DEPFLAGS = -MT $@ -MMD -MP -MF $(DEPDIR)/$*.d

CPPFLAGS := --target=i686-pc-windows-msvc -msse -msse2 -mfpmath=sse -O3 -fno-exceptions -fno-rtti -fno-builtin-printf -fno-threadsafe-statics -fwrapv -fno-math-errno \
	-D_HAS_EXCEPTIONS=0 -D_CRTIMP=__declspec(dllimport) -D_VCRTIMP=__declspec(dllimport) -D_CRT_SECURE_NO_WARNINGS=1 -Isrc

all: th18.v1.00a.js $(FXCS) $(ECLS) $(ANMS)

clean:
	rmdir build /s /q

th18.v1.00a.js: build/linked.obj um_chaos.json
	python tools/coff2binhack.py um_chaos.json

build/linked.obj: $(OBJS)
	tools/ld -m i386pe --oformat pe-i386 -r $(OBJS) -o $@

build/%.obj: src/%.cpp $(DEPDIR)/%.d | $(DEPDIR)
	-@if not exist $(addprefix ",$(addsuffix ",$(dir $@))) ( \
		mkdir $(addprefix ",$(addsuffix ",$(dir $@))) \
	)
	-@if not exist $(addprefix ",$(addsuffix ",$(dir $(DEPDIR)/$*.d))) ( \
		mkdir $(addprefix ",$(addsuffix ",$(dir $(DEPDIR)/$*.d))) \
	)
	clang $(DEPFLAGS) $(CPPFLAGS) -c $(OUTPUT_OPTION) $<

th18/%.ecl: src/%.tecl
	tools/thecl.exe -c 18 -m tools/th18.eclm $< $@

th18/%.anm: src/%.tanm
	tools/truanm.exe compile -g 18 -i src/anm $< -o $@

th18/%_vs.fxc: src/%_vs.hlsl
	fxc /T vs_3_0 /Fo $@ $<

th18/%_ps.fxc: src/%_ps.hlsl
	fxc /T ps_3_0 /Fo $@ $<

$(DEPDIR)/%.d: ;
.PRECIOUS: $(DEPDIR)/%.d
$(DEPDIR): ; -@mkdir $(addprefix ",$(addsuffix ",$@))

DEPFILES := $(SRCS:src/%.cpp=$(DEPDIR)/%.d)
$(DEPFILES):
include $(wildcard $(DEPFILES))
