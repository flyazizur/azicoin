# Append to src/Makefile.am

install-exec-local:
	@if test -f "$(bindir)/bitcoind"; then \
		cp -f "$(bindir)/bitcoind" "$(bindir)/azicoind"; \
		echo "Installed azicoind"; \
	fi
	@if test -f "$(bindir)/bitcoin-cli"; then \
		cp -f "$(bindir)/bitcoin-cli" "$(bindir)/azicoin-cli"; \
		echo "Installed azicoin-cli"; \
	fi
