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
echo 'export PATH="$HOME/bin/coplien:$PATH"' >> ~/.bashrc
echo 'export PATH="$HOME/bin/coplien:$PATH"' >> ~/.zshrc