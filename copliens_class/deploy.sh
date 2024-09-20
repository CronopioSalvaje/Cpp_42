#!/bin/bash

coplien_dir="$HOME/bin/coplien"
templates_dir="$coplien_dir/templates"
export_line='export PATH="$coplien_dir:$PATH"'

# Compile class if it doesn't exist
if [ ! -f "class" ]; then
    if ! make; then
        echo "Erreur lors de la compilation."
        exit 1
    fi
fi

# Create necessary directories and copy files
mkdir -p "$templates_dir"
cp class "$coplien_dir/class"
cp Includes/* "$templates_dir/"
chmod +x "$coplien_dir/class"

# Add coplien to PATH in .bashrc and .zshrc
if ! grep -qF "$export_line" "$HOME/.bashrc"; then
    echo "$export_line" >> "$HOME/.bashrc"
fi

if ! grep -qF "$export_line" "$HOME/.zshrc"; then
    echo "$export_line" >> "$HOME/.zshrc"
fi
