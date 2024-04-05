SRCS = $(wildcard src/*.cpp) $(wildcard src/effects/*.cpp)
OBJS = $(patsubst src/%.cpp,build/%.obj,$(SRCS))

DEPDIR := build/.deps
DEPFLAGS = -MT $@ -MMD -MP -MF $(DEPDIR)/$*.d

CPPFLAGS := --target=i686-pc-windows-msvc -msse -msse2 -mfpmath=sse -O3 -fno-exceptions -fno-rtti -fno-builtin-printf -D_HAS_EXCEPTIONS=0 "-D_CRTIMP=__declspec(dllimport)" "-D_VCRTIMP=__declspec(dllimport)" -D_CRT_SECURE_NO_WARNINGS=1 -Isrc

all: build/linked.obj um_chaos.json
	python ../../misc/reversing/touhou/coff2binhack/coff2binhack.py um_chaos.json

clean:
	rmdir build /s /q

build/linked.obj: $(OBJS)
	ld -m i386pe --oformat pe-i386 -r $(OBJS) -o $@

build/%.obj: src/%.cpp $(DEPDIR)/%.d | $(DEPDIR)
	-@mkdir $(addprefix ",$(addsuffix ",$(dir $@)))
	-@mkdir $(addprefix ",$(addsuffix ",$(dir $(DEPDIR)/$*.d)))
	clang $(DEPFLAGS) $(CPPFLAGS) -c $(OUTPUT_OPTION) $<

$(DEPDIR)/%.d: ;
.PRECIOUS: $(DEPDIR)/%.d
$(DEPDIR): ; -@mkdir $(addprefix ",$(addsuffix ",$@))

DEPFILES := $(SRCS:src/%.cpp=$(DEPDIR)/%.d)
$(DEPFILES):
include $(wildcard $(DEPFILES))
