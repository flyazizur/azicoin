.PHONY: all genesis_finder
all: genesis_finder

# This helper target attempts to build the genesis_finder tool using the repository's
# existing src build targets. It does not try to reimplement Bitcoin Core's build system;
# instead it delegates to the src Makefile which knows how to build project binaries.
# Usage (from repo root): make -f tools/Makefile genesis_finder

genesis_finder:
	@echo "Building genesis_finder via src build targets..."
	$(MAKE) -C src genesis_finder || { echo "Could not build genesis_finder via src target; trying full build..."; $(MAKE) -C src; $(MAKE) -C src genesis_finder; }
	@echo "If the above succeeded, the binary will be in src/genesis_finder or src/tools/genesis_finder depending on your build system."