#!/bin/sh
# After building, this helper renames the built binaries to AZI names
# Usage: run from root of repo after `make` (binaries are in src/)
set -e
SRC_DIR=src
if [ -f "$SRC_DIR/bitcoind" ]; then
    cp "$SRC_DIR/bitcoind" "$SRC_DIR/azicoind" && echo "Created $SRC_DIR/azicoind"
fi
if [ -f "$SRC_DIR/bitcoin-cli" ]; then
    cp "$SRC_DIR/bitcoin-cli" "$SRC_DIR/azicoin-cli" && echo "Created $SRC_DIR/azicoin-cli"
fi
