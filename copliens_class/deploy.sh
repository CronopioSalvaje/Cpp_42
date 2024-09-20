#!/bin/bash

if [ ! -f "class" ];
then
    make
fi

mkdir -p $HOME/bin/coplien/templates/
cp class $HOME/bin/coplien/class
cp Includes/* $HOME/bin/coplien/templates/
chmod +x $HOME/bin/coplien/class
export PATH="$HOME/bin/coplien:$PATH"

if  ! grep -q 'export PATH="$HOME/bin/coplien:$PATH"' "$HOME/.bashrc"; then
  echo 'export PATH="$HOME/bin/coplien:$PATH"' >> ~/.bashrc
fi

if  ! grep -q 'export PATH="$HOME/bin/coplien:$PATH"' "$HOME/.zshrc"; then
  echo 'export PATH="$HOME/bin/coplien:$PATH"' >> ~/.zshrc
fi
