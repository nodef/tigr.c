#!/usr/bin/env bash
# Fetch the latest version of the library
fetch() {
if [ -d "tigr" ]; then return; fi
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
fi
cd ..

# Copy the libs to the package directory
echo "Copying libs to tigr/ ..."
rm -rf tigr
mkdir -p tigr
cp -f ".build/$DIR/tigr.h" tigr/
cp -f ".build/$DIR/tigr.c" tigr/
}


# Test the project
test() {
echo "Running 01-hello-world.c ..."
clang -I. -o 01.exe examples/01-hello-world.c   && ./01.exe && echo -e "\n"
echo "Running 02-animation.c ..."
clang -I. -o 02.exe examples/02-animation.c     && ./02.exe && echo -e "\n"
echo "Running 03-input.c ..."
clang -I. -o 03.exe examples/03-input.c         && ./03.exe && echo -e "\n"
echo "Running 04-image-loading.c ..."
clang -I. -o 04.exe examples/04-image-loading.c && ./04.exe && echo -e "\n"
echo "Running 05-pixel-shader.c ..."
clang -I. -o 05.exe examples/05-pixel-shader.c  && ./05.exe && echo -e "\n"
}


# Main script
if [[ "$1" == "test" ]]; then test
elif [[ "$1" == "fetch" ]]; then fetch
else echo "Usage: $0 {fetch|test}"; fi
