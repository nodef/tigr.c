#!/usr/bin/env bash
URL="https://github.com/erkkah/tigr/archive/refs/tags/v3.2.2.zip"
ZIP="${URL##*/}"
DIR="${ZIP%.zip}"
DIR="tigr-${DIR/v/}"
mkdir -p .build
cd .build

# Download the release
if [ ! -f "$ZIP" ]; then
  echo "Downloading $ZIP from $URL ..."
  rm -rf "$ZIP"
  curl -L "$URL" -o "$ZIP"
  echo ""
fi

# Unzip the release
if [ ! -d "$DIR" ]; then
  echo "Unzipping $ZIP to .build/$DIR ..."
  rm -rf "$DIR"
  cp "$ZIP" "$ZIP.bak"
  unzip -q "$ZIP"
  rm "$ZIP"
  mv "$ZIP.bak" "$ZIP"
  echo ""
fi

# Copy the libs to the package directory
echo "Copying libs to tigr/ ..."
rm -rf ../tigr
mkdir -p ../tigr
cp -f "$DIR/tigr.h" ../tigr/
cp -f "$DIR/tigr.c" ../tigr/
echo ""
